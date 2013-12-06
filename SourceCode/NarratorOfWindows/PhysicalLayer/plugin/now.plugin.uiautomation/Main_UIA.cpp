#include "NowDefine_UIA.h"
#include "INowPlugin.h"
#include "NowPlugin_UIA.h"

//#define EOF (-1)

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif

	__declspec(dllexport) INowPlugin* __cdecl myPuts(LPWSTR lpszMsg)
	{
		printf("__declspec(dllexport) int __cdecl myPuts()\n");
		
		NowPlugin* plugin = new NowPlugin();

		return (INowPlugin*) plugin;
	}

#ifdef __cplusplus
}
#endif