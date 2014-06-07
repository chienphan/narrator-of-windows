using System;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.argument;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.storage;
using System.Windows.Automation;

namespace now.agent.uiautomation.client.action.common
{
    class GetProperty : INowUIAAction
    {
        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;

            String strSignatureControl = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_SIGNATURE);
            String propertyName = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_PROPERTY_NAME);

            AutomationElement runtimeElement = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement == null)
            {
                runtimeElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignatureControl);
            }

            if (runtimeElement != null)
            {
                String value = NowUIAService.GetInstance().GetUIProperty(runtimeElement, propertyName);
                NowUIAArgumentOut.GetInstance().Data = value;
                nResult = NowUIADefine.NOW_OK;
            }

            return nResult;
        }
    }
}
