#include "NowActionClearCache.h"
#include "NowStorage.h"
#include "NowPluginManager.h"
#include "NowLogger.h"

NowActionClearCache::NowActionClearCache(void)
{
}


NowActionClearCache::~NowActionClearCache(void)
{
}

NOW_RESULT NowActionClearCache::prepareArguments( vector<wstring>* argumnents )
{
	return NOW_OK;
}

NOW_RESULT NowActionClearCache::doAction()
{
	NowLogger::getInstance()->LogAString("[NowActionClearCache::doAction]");
	NowStorage::getInstance()->emptyStorage();
	
	NowListPlugins lstPlugins = NowPluginManager::getInstance()->getListPlugins();
	vector<INowPlugin*>::iterator it = lstPlugins->begin();
	for (; it != lstPlugins->end(); it++)
	{
		(*it)->clearCache();
	}
	return NOW_OK;
}
