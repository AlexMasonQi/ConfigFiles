#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Configs.h"

/*Global Variables*/
char *FileName = "E:/test/TestConfigFile1.ini";

/*Display UI*/
void DisplayUI()
{
	printf("Creat and read the configuration files.\n");
	printf("The number description:\n");
	printf("0-Exit the program\n");
	printf("1-Test to config the configuration files\n");
	printf("2-Test to read the configuration files");
}

int CreatConfigFiles()
{
	int ret = 0;
	char ItemName[1024] = { 0 };
	char ItemValue[1024] = { 0 };
	printf("\nPlease input the Name:");
	scanf("%s", ItemName);
	printf("\nPlease input the KeyValue:");
	scanf("%s", ItemValue);
	ret = WriteConfigItem(FileName, ItemName, ItemValue,strlen(ItemValue));
	if (ret != 0)
	{
		printf("The function \"WriteConfigItem\" error\n");
		exit(1);
	}
	printf("%s = %s\n", ItemName, ItemValue);
	return ret;
}
int ReadConfigFiles()
{
	int ret = 0;
	char ItemName[1024] = { 0 };
	char ItemValue[1024] = { 0 };

	printf("\nPlease input the Name:");
	scanf("%s", ItemName);
	ret = GetConfigItem(FileName,ItemName,ItemValue,strlen(ItemValue) );
	if (ret != 0)
	{
		printf("The function \"WriteConfigItem\" error\n");
		exit(1);
	}
	printf("%s = %s\n", ItemName, ItemValue);
	return ret;
}
int main()
{
	int CodeNum = 0;
	DisplayUI();
	scanf("%d", &CodeNum);
	while (1)
	{
		switch (CodeNum)
		{
			case 0:
			case 1:
			case 2:
		}
	}
	system("pause");
	return 0;
}