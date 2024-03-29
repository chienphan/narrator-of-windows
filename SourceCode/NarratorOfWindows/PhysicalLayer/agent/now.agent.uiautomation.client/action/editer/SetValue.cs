﻿using System;
using System.Windows.Automation;
using now.agent.uiautomation.client.argument;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.pattern;
using now.agent.uiautomation.client.storage;

namespace now.agent.uiautomation.client.action.editer
{
    class SetValue : INowUIAAction
    {
        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;

            String strSignatureControl = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_SIGNATURE);
            String strValue = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_VALUE);

            AutomationElement runtimeElement = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement != null)
            {
                nResult = NowValuePattern.GetInstance().SetValue(runtimeElement, strValue);
            }

            return nResult;
        }
    }
}
