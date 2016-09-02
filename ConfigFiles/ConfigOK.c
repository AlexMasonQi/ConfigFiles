#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Configs.h"

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
int WriteConfigItem(char *pFileName,char *pItemName, char *pValue, int ItemValuelen)
{
	int ret = 0;
	FILE *fp;
	fp = fopen(pFileName, "a+");
	//char buffer[1024];
	if (fp == NULL)
	{
		printf("Error to open or creat the file!\n");
		ret = -1;
		exit(-1);
	}
	strcat(pItemName, " = ");
	strcat(pItemName, pValue);
	/*pItemName[strlen(pItemName)] = "\n";
	pItemName[strlen(pItemName) + 1] = '\0';*/
	/*while (!feof(fp))
	{
		fgets(buffer, strlen(buffer), fp);
		if (buffer != NULL)
		{
			strcat(buffer, "\n");
			break;
		}
	}	*/
	int Valuelen = fputs(pItemName, fp);
	ItemValuelen = Valuelen;
	if (fp != NULL)
	{
		fclose(fp);
	}
	return ret;
}