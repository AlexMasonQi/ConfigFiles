#pragma once

#ifndef _CONFIGS_H_
#define _CONFIGS_H_
#ifdef _cplusplus
extern "C" {
#endif

	/*Get the Configuration options*/
	int GetConfigItem(char *pFileName, char *pKey, char *pValue, int pValueLen);
	/*Write the Configuration options*/
	int WriteConfigItem(char *pFileName,char *pItemName, char *pValue, int ItemValueLen);


#ifdef _cplusplus
}
#endif
#endif


