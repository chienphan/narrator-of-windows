#include "NowDefine.h"
#include "NowPlugin_UIA.h"

#ifdef __cplusplus    
extern "C" {     
#endif

	__declspec(dllexport) INowPlugin* __cdecl initialize()
	{		
		return (INowPlugin*) NowPlugin_UIA::getInstance();
	}

#ifdef __cplusplus
}
#endif