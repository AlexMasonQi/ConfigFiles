#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Configs.h"

/*Get the Configuration options*/
int GetConfigItem(char *pFileName, char *pKey)
{
	char *KeyValue=NULL;
	int ret = 0;
	FILE *fp = NULL;
	fp = fopen(pFileName, "a+");
	if (fp == NULL)
	{
		printf("Error to open or creat the file!\n");
		ret = -1;
		exit(-1);
	}
	KeyValue = fgets(KeyValue, strlen(KeyValue), fp);
	char *p = strstr(KeyValue, pKey);
	pKey = p;
	return ret;
}

/*Write the Configuration options*/
int WriteConfigItem(char *pFileName,char *pItemName, char *pValue, int ItemValuelen)
{
	int ret = 0;
	FILE *fp;
	fp = fopen(pFileName, "a+");
	if (fp == NULL)
	{
		printf("Error to open or creat the file!\n");
		ret = -1;
		exit(-1);
	}
	strcat(pItemName, " = ");
	strcat(pItemName, pValue);
	int Valuelen = fputs(pItemName, fp);
	ItemValuelen = Valuelen;
	if (fp != NULL)
	{
		fclose(fp);
	}
	return ret;
}