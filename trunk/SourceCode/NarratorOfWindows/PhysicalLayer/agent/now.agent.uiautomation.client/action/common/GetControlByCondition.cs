using System;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.argument;
using System.Windows.Automation;
using now.agent.uiautomation.client.storage;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client.action.common
{
    class GetControlByCondition : INowUIAAction
    {
        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;

            String strWindowHandle = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_WINDOW_HANDLE);
            String strPropsData = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_DATA);

            AutomationElement window = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strWindowHandle);
            if (window != null)
            {
                //NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] window: " + window.Current.Name);
                Condition condControl = NowUIAService.GetInstance().GetCondition(strPropsData);
                if (condControl != null)
                {
                    AutomationElement control = window.FindFirst(TreeScope.Descendants, condControl);
                    if (control != null)
                    {
                        //NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] control: " + control.Current.Name);
                        String strSignatureControl = NowUIAService.GetInstance().GetSignature(control);
                        String strControlType = control.Current.LocalizedControlType;
                        NowUIAArgumentOut.GetInstance().Data = strSignatureControl + "|" + strControlType;

                        NowUIAStorageAction.GetInstance().AddToCache(strSignatureControl, control);
                        nResult = NowUIADefine.NOW_OK;
                    }
                    else
                    {
                        NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] control: NULL");
                    }
                }
            }
            else
            {
                NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] window: NULL");
            }

            return nResult;
        }
    }
}
