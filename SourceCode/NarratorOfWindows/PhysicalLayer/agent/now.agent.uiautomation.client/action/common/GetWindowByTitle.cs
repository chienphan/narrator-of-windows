using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Windows.Automation;
using now.agent.uiautomation.client.argument;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.logger;
using now.agent.uiautomation.client.storage;
using now.agent.uiautomation.client.utility;

namespace now.agent.uiautomation.client.action.common
{
    class GetWindowByTitle : INowUIAAction
    {
        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;

            String strTitleWindow = NowUIAArgumentIn.GetInstance().GetStringArgument(NowUIAPropertyDefine.UIA_PROP_WINDOW_TITLE);

            AutomationElement currentWindow = null;

            //check for regular expression
            if (NowUIAUtilities.GetInstance().IsRegExpPattern(strTitleWindow))
            {
                strTitleWindow = NowUIAUtilities.GetInstance().TrimRegExpPattern(strTitleWindow);
            }

            //get all windows
            List<AutomationElement> listWindow = new List<AutomationElement>();
            TreeWalker rawView = TreeWalker.RawViewWalker;
            currentWindow = rawView.GetFirstChild(AutomationElement.RootElement);

            while (currentWindow != null)
            {
                //NowUIALogger.GetInstance().LogInfor(">>>" + currentWindow.Current.Name);
                listWindow.Add(currentWindow);
                currentWindow = rawView.GetNextSibling(currentWindow);
            }

            //find the window has strTitleWindow
            foreach (AutomationElement window in listWindow)
            {
                if (Regex.IsMatch(window.Current.Name, strTitleWindow))
                {
                    //NowUIALogger.GetInstance().LogInfor("IsMatch:" + window.Current.Name + "|" + window.Current.NativeWindowHandle);
                    currentWindow = window;
                    nResult = NowUIADefine.NOW_OK;
                    break;
                }
            }

            if (nResult == NowUIADefine.NOW_OK)
            {
                //keep the window element to cache and return strHandleWindow
                String strHandleWindow = String.Format("{0}", currentWindow.Current.NativeWindowHandle);
                NowUIAArgumentOut.GetInstance().Data = strHandleWindow;
                NowUIAStorageAction.GetInstance().AddToCache(strHandleWindow, currentWindow);
            }

            return nResult;
        }
    }
}
