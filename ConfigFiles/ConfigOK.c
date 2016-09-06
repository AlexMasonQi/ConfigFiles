#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Configs.h"
int Tag = 0;

/*Delete the space in the string*/
int TrimSpace(char *instr, char *outstr)
{
	int ret = 0;
	char *non_str = instr;
	if (non_str == NULL)
	{
		ret = -1;
		printf("Error input!\n");
		exit(-1);
	}
	int i = 0;
	int j = 0;
	j = strlen(non_str) - 1;
	while ((isspace(non_str[i])) && (non_str[i]) != '\0')
	{
		i++;
	}
	while ((isspace(non_str[j])) && (non_str[j]) != '\0')
	{
		j--;
	}
	int num = j - i + 1;
	strncpy(outstr, non_str+i, num);
	outstr[num] = '\0';
	return ret;
}

/*Get the Configuration options*/
int GetConfigItem(char *pFileName, char *pKey)
{
	int ret_TrimSpace = 0;
	char KeyValue[1024];
	char out_str[1024] = { 0 };
	char *out = NULL;
	int ret = 0;
	FILE *fp = NULL;
	char *temp = NULL;
	if (pFileName == NULL || pKey == NULL )
	{
		printf("Error input!\n");
		ret = -1;
		exit(-1);
	}
	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		printf("Error to open or creat the file!\n");
		ret = -1;
		exit(-1);
	}
	while (!feof(fp))
	{
		//memset(temp, 0, strlen(temp));
		fgets(KeyValue, strlen(KeyValue), fp);
		temp = strchr(KeyValue, '=');//Judge whether the character '=' exist 
		if (temp == NULL)
		{
			continue;
		}
		temp = strstr(KeyValue, pKey);
		if (temp == NULL)
		{
			continue;
		}
		temp = temp + strlen(pKey);
		temp = strchr(temp, '=');
		if (temp == NULL)
		{
			continue;
		}
		temp += 1;
		ret_TrimSpace = TrimSpace(temp, out_str);
		strcat(pKey, "=");
		out = strcat(pKey, out_str);
	}
	printf("%s\n", out);
	if (fp != NULL)
	{
		fclose(fp);
	}
	return ret;
}

/*Write the Configuration options*/
int WriteConfigItem(char *pFileName,char *pItemName, char *pValue)
{
	FILE *fp = NULL;
	int ret = 0;
	char *Linebuf[1024];
	char *Filebuf[1024] = { 0 };
	char *temp = NULL;
	if (pFileName == NULL || pItemName == NULL || pValue == NULL)
	{
		ret = -1;
		printf("Error input!\n");
		exit(-1);
	}
	fp = fopen(pFileName, "r+");
	if (fp == NULL)
	{
		ret = -2;
		printf("The file \"TestConfigFile1.ini\" does not exist!\n");
		//goto END;
	}
	if (fp == NULL)
	{
		fp = fopen(pFileName, "wt+");
		if (fp == NULL)
		{
			ret = -3;
			printf("The file \"TestConfigFile1.ini\" does not exist!\n");
		}
	}
	while (!feof(fp))
	{
		memset(Linebuf, 0, sizeof(Linebuf));
		temp = fgets(Linebuf, strlen(Linebuf), fp);
		if (temp == NULL)
		{
			break;
		}
		temp = strstr(Linebuf, pItemName);
		if (temp == NULL)
		{
			strcat(Filebuf, Linebuf);
			continue;
		}
		else
		{
			sprintf(Linebuf, "%s=%s\n", pItemName, pValue);
			strcat(Filebuf, Linebuf);
			Tag = 1;
		}
	}
	if (Tag == 0)
	{
		fprintf(fp, "%s=%s\n", pItemName, pValue);
	}
	else
	{
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}
		fp = fopen(pFileName, "wt+");
		if (fp == NULL)
		{
			ret = -4;
			printf("The file \"TestConfigFile1.ini\" does not exist!\n");
			goto END;
		}
		fputs(Filebuf, fp);
	}
END:
	if (fp != NULL)
	{
		fclose(fp);
	}
}