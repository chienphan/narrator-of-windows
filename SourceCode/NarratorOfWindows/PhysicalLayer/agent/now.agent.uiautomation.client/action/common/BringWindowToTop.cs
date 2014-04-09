using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.logger;
using now.agent.uiautomation.client.storage;
using System.Windows.Automation;
using now.agent.uiautomation.client.argument;
using System;

namespace now.agent.uiautomation.client.action.common
{
    class BringWindowToTop : INowUIAAction
    {
        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;

            String strWindowSignature = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_SIGNATURE);

            AutomationElement window = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strWindowSignature.Trim());
            //NowUIALogger.GetInstance().LogInfor("[BringWindowToTop] GetUIObjectFormCache");
            if (window != null)
            {
                //NowUIALogger.GetInstance().LogInfor("[BringWindowToTop] window: not NULL");
                object obj = window.GetCurrentPropertyValue(AutomationElement.IsWindowPatternAvailableProperty);
                if (obj != null)
                {
                    bool hasWindowPattern = (bool)obj;
                    if (hasWindowPattern == true)
                    {
                        //NowUIALogger.GetInstance().LogInfor("[BringWindowToTop] hasWindowPattern");
                        obj = window.GetCurrentPattern(WindowPattern.Pattern);
                        if (obj != null)
                        {
                            WindowPattern windowPattern = obj as WindowPattern;
                            windowPattern.SetWindowVisualState(WindowVisualState.Normal);
                            nResult = NowUIADefine.NOW_OK;
                        }
                    }
                }
            }

            return nResult;
        }
    }
}
