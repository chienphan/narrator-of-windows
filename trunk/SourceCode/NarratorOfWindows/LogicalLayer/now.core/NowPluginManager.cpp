#include "NowPluginManager.h"
#include "NowDefine.h"
#include "INowPlugin.h"
#include "NowDevice.h"
#include "NowLogger.h"

NowPluginManager::NowPluginManager(void)
{
	m_strSignature = "";
}

NowPluginManager::~NowPluginManager(void)
{
}

INowPlugin* NowPluginManager::LoadPlugins()
{
	//TODO:need to implement to load many plugins
	list<string>* lstPluginFileName = NowDevice::getAllFilesInDirectory(NowDevice::getCurrentDirectory() + "\\plugin", "dll");

	string strUIPlugin = "";

	if (lstPluginFileName != NULL)
	{
		if (lstPluginFileName->size() > 0)
		{
			strUIPlugin = *(lstPluginFileName->begin());
			OutputDebugStringA(strUIPlugin.c_str());
		}
	}
	

	HINSTANCE hinstLib; 
	NOW_PROC ProcAdd; 
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE; 

	// Get a handle to the DLL module.

	//hinstLib = LoadLibrary(TEXT("plugin\\now.plugin.uiautomation.dll")); 
	string pluginFullPath = NowDevice::getCurrentDirectory() + "\\plugin\\" + strUIPlugin ;
	hinstLib = LoadLibrary(pluginFullPath.c_str()); 

	// If the handle is valid, try to get the function address.

	if (hinstLib != NULL) 
	{ 
		OutputDebugStringA("hinstLib != NULL");
		ProcAdd = (NOW_PROC) GetProcAddress(hinstLib, "initialize"); 

		// If the function address is valid, call the function.

		if (NULL != ProcAdd) 
		{
			OutputDebugStringA("hinstLib != NULL");
			fRunTimeLinkSuccess = TRUE;
			INowPlugin* plugin = (ProcAdd) (); 
			
			if (plugin != 0)
			{
				OutputDebugStringA("plugin != 0");
				return plugin;
			}
		}
		// Free the DLL module.

		fFreeResult = FreeLibrary(hinstLib); 
	} 

	// If unable to call the DLL function, use an alternative.
	if (! fRunTimeLinkSuccess) 
		//NowLogger::getInstance()->LogAString("[NowPluginManager::LoadPlugin]Message printed from executable\n");
		//printf("Message printed from executable\n"); 

	system("pause");
	return 0;
}

bool NowPluginManager::isChangedControl( const string& strSignature )
{
	if (!strSignature.empty() && (strSignature.compare(m_strSignature) != 0))
	{
		//control is changed
		m_strSignature = strSignature;
		return true;
	}
	return false;
}
