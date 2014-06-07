#include "NowDefine.h"
#include "NowPlugin_UIA.h"

//#define EOF (-1)

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif

	__declspec(dllexport) INowPlugin* __cdecl initialize()
	{		
		//NowPlugin_UIA* plugin = ;
		return (INowPlugin*) NowPlugin_UIA::getInstance();
	}

#ifdef __cplusplus
}
#endif