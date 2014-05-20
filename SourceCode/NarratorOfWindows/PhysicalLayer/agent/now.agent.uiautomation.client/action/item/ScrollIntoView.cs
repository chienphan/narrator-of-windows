using System;
using System.Windows.Automation;
using now.agent.uiautomation.client.argument;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.storage;
using now.agent.uiautomation.client.pattern;

namespace now.agent.uiautomation.client.action.item
{
    class ScrollIntoView : INowUIAAction
    {
        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;

            String strSignatureControl = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_SIGNATURE);

            AutomationElement runtimeElement = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement != null)
            {
                nResult = NowScrollItemPattern.GetInstance().ScrollIntoView(runtimeElement);
            }

            return nResult;
        }
    }
}
