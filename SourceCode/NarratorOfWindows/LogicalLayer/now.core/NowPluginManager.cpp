#include "NowPluginManager.h"
#include "NowDefine.h"
#include "INowPlugin.h"
#include "NowDevice.h"
#include "NowLogger.h"
#include "INowControl.h"

NowPluginManager* NowPluginManager::m_instance = NULL;
NowListPlugins NowPluginManager::m_lstPlugins = NULL;

NowPluginManager::NowPluginManager(void)
{
	m_strSignature = "";
	m_control = NULL;
	m_lstPlugins = loadPlugins();
}

NowPluginManager::~NowPluginManager(void)
{
}

NowPluginManager* NowPluginManager::getInstance()
{
	if (!m_instance)
	{
		m_instance = new NowPluginManager();
	}
	return m_instance;
}

NowListPlugins NowPluginManager::loadPlugins()
{
	NowListPlugins lstPlugin = new vector<INowPlugin*>();
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
		NowLogger::getInstance()->LogAString(pluginFullPath);
		hinstLib = LoadLibrary(pluginFullPath.c_str()); 

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
					NowLogger::getInstance()->LogAString("Push to list!");
					lstPlugin->push_back(plugin);
				}
			}
			// Free the DLL module.
			//fFreeResult = FreeLibrary(hinstLib); 
		} 

		// If unable to call the DLL function, use an alternative.
		if (! fRunTimeLinkSuccess) 
		{
			NowLogger::getInstance()->LogAString("Unable to call the DLL function");
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

NowListPlugins NowPluginManager::getListPlugins()
{
	return m_lstPlugins;
}

INowControl* NowPluginManager::getControlFromCache( const string& strSignature )
{
	if (m_control != NULL)
	{
		string currentSignature = "";
		if (NOW_SUCCEED(m_control->getSignature(currentSignature)))
		{
			if (currentSignature.compare(strSignature) == 0)
			{
				return m_control;
			}
		}
	}
	return NULL;
}

NOW_RESULT NowPluginManager::keepControlToCache( INowControl* pControl )
{
	NOW_RESULT nResult = NOW_FALSE;
	//TODO: Need to delete pointer after assign new pointer
	if (pControl != NULL)
	{
		INowControl* pTemp = m_control;
		m_control = pControl;
		//delete old control
		delete pTemp;
		nResult = NOW_OK;
	}
	
	return nResult;
}
