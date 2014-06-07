using System;
using System.Windows.Automation;
using now.agent.uiautomation.client.argument;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.logger;
using now.agent.uiautomation.client.storage;

namespace now.agent.uiautomation.client.action.common
{
    class GetStatus : INowUIAAction
    {
        public int DoAction()
        {
            //[Apr 9 2014] Chien.Phan TODO: this action work incorrect. 
            //Need to check it laster 
            //NowUIALogger.GetInstance().LogInfor("[GetStatus.DoAction] IN");
            int nResult = NowUIADefine.NOW_FALSE;

            String strSignatureControl = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_SIGNATURE);

            AutomationElement runtimeElement = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement == null)
            {
                runtimeElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignatureControl);
            }
            if (runtimeElement != null)
            {
                int nState = 0;
                nResult = NowUIAService.GetInstance().GetStatus(runtimeElement, ref nState);
                NowUIAArgumentOut.GetInstance().Data = nState;
                //NowUIALogger.GetInstance().LogInfor("[GetStatus.DoAction] nState=" + nState);
            }
            return nResult;
        }
    }
}
