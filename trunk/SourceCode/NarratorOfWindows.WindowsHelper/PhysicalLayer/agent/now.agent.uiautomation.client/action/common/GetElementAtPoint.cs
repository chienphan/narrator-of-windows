using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.argument;
using System;
using System.Windows.Automation;
using now.agent.uiautomation.client.storage;
using System.Windows;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client.action.common
{
    class GetElementAtPoint : INowUIAAction
    {
        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;
            
            int x = NowUIAArgumentIn.GetInstance().GetIntArgument(NowUIAPropertyDefine.UIA_PROP_POINT_X);
            int y = NowUIAArgumentIn.GetInstance().GetIntArgument(NowUIAPropertyDefine.UIA_PROP_POINT_Y);

            AutomationElement currentElement = null;

            try
            {
                //Get element at point
                currentElement = AutomationElement.FromPoint(new Point((double)x, (double)y));
                if (currentElement != null)
                {
                    //TODO: Need check for control type and decide the control to return
                    // Get signature, control type and create cache
                    String strControlType = currentElement.Current.LocalizedControlType; //TODO: Need check for get LocalizedControlType or ControlType
                    String strSignatureControl = NowUIAService.GetInstance().GetSignature(currentElement);
                    NowUIAStorage.GetInstance().AddToCache(strSignatureControl, currentElement);

                    NowUIAArgumentOut.GetInstance().Data = strSignatureControl + "|" + strControlType;

                    nResult = NowUIADefine.NOW_OK;
                }
            }
            catch (System.Exception ex)
            {
                NowUIALogger.GetInstance().LogError("[NowUIACommunication][GetElementAtPoint] Exception [{0}]", ex.Message);
            }
            return nResult;
        }
    }
}
