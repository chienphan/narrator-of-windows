#include "NowPluginManager.h"
#include "NowDefine.h"
#include "INowPlugin.h"

NowPluginManager::NowPluginManager(void)
{
}

NowPluginManager::~NowPluginManager(void)
{
}

INowPlugin* NowPluginManager::LoadPlugins()
{
	HINSTANCE hinstLib; 
	NOW_PROC ProcAdd; 
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE; 

	// Get a handle to the DLL module.

	hinstLib = LoadLibrary(TEXT("plugin\\now.plugin.uiautomation.dll")); 

	// If the handle is valid, try to get the function address.

	if (hinstLib != NULL) 
	{ 
		ProcAdd = (NOW_PROC) GetProcAddress(hinstLib, "initialize"); 

		// If the function address is valid, call the function.

		if (NULL != ProcAdd) 
		{
			fRunTimeLinkSuccess = TRUE;
			INowPlugin* plugin = (ProcAdd) (); 
			
			if (plugin != 0)
			{
				return plugin;
			}
		}
		// Free the DLL module.

		fFreeResult = FreeLibrary(hinstLib); 
	} 

	// If unable to call the DLL function, use an alternative.
	if (! fRunTimeLinkSuccess) 
		printf("Message printed from executable\n"); 

	system("pause");
	return 0;
}
