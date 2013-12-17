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

vector<INowPlugin*>* NowPluginManager::LoadPlugins()
{
	//TODO:need to implement to load many plug-ins
	vector<INowPlugin*>* lstPlugin = new vector<INowPlugin*>();
	vector<string>* lstPluginFileName = NULL;

	string strDebugMode = "";
	string strDebugDir = "";
	strDebugMode = NowDevice::getEnvironmentVariable(NOW_DEBUG_MODE);
	if (strDebugMode.empty() || strDebugMode.compare("1") != 0)
	{
		strDebugDir = NowDevice::getCurrentDirectory();
	}
	else
	{
		strDebugDir = NowDevice::getEnvironmentVariable(NOW_DEBUG_DIRECTORY);
	}

	lstPluginFileName = NowDevice::getAllFilesInDirectory(strDebugDir + "\\plugin", "dll");
	
	HINSTANCE hinstLib; 
	NOW_PROC ProcAdd; 
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE; 
	string pluginFullPath = "";

	// Get a handle to the DLL module.
	for (std::vector<string>::iterator it = lstPluginFileName->begin() ; it != lstPluginFileName->end(); ++it)
	{
		pluginFullPath = strDebugDir + "\\plugin\\" + *it;
		OutputDebugStringA(pluginFullPath.c_str());
		hinstLib = LoadLibrary(pluginFullPath.c_str()); 

		// If the handle is valid, try to get the function address.

		if (hinstLib != NULL) 
		{ 
			OutputDebugStringA("Get Proc Address");
			ProcAdd = (NOW_PROC) GetProcAddress(hinstLib, "initialize"); 

			// If the function address is valid, call the function.

			if (NULL != ProcAdd) 
			{
				OutputDebugStringA("Call Proc Address");
				fRunTimeLinkSuccess = TRUE;
				INowPlugin* plugin = (ProcAdd) (); 

				if (plugin != 0)
				{
					OutputDebugStringA("push_back!!!");
					lstPlugin->push_back(plugin);
				}
			}
			// Free the DLL module.
			//fFreeResult = FreeLibrary(hinstLib); 
		} 

		// If unable to call the DLL function, use an alternative.
		if (! fRunTimeLinkSuccess) 
		{
			OutputDebugStringA("Message printed from executable");
		}
	}

	return lstPlugin;
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
