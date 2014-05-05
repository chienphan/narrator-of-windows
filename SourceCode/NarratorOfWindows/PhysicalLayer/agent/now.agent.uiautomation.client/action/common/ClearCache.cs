using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.storage;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client.action.common
{
    class ClearCache : INowUIAAction
    {
        public int DoAction()
        {
            NowUIALogger.GetInstance().LogInfor("[ClearCache::DoAction]");
            NowUIAStorage.GetInstance().ClearCache();
            NowUIAStorageAction.GetInstance().ClearCache();
            return NowUIADefine.NOW_OK;
        }
    }
}
