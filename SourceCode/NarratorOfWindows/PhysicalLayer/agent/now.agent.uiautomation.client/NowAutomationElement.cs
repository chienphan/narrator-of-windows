using System.Windows.Automation;
using System.Windows;

namespace now.agent.uiautomation.client
{
    public class NowAutomationElement
    {
        public string GetElementAtPoint(int x, int y)
        {
            string strResult = "";
            //System.Console.WriteLine("[GetElementAtPoint] [{0}][{1}]", x, y);

            Point pt = new Point(x, y);
           
            AutomationElement currentElement =  AutomationElement.FromPoint(pt);
            System.Console.WriteLine("[GetElementAtPoint] [{0}][{1}][{2}]", x, y, currentElement.Current.LocalizedControlType);
            return strResult = currentElement.Current.LocalizedControlType;
        }
    }
}
