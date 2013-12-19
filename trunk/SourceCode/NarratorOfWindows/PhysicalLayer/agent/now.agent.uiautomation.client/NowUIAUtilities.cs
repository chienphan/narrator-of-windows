using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace now.agent.uiautomation.client
{
    public class NowUIAUtilities
    {
        private static NowUIAUtilities m_instance = null;

        private NowUIAUtilities()
        {
        }

        public static NowUIAUtilities GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIAUtilities();
            }
            return m_instance;
        }

        public String GetEnvironmentVariableValue(String strVariable)
        {
            return Environment.GetEnvironmentVariable(strVariable);
        }

        public String GetCurrentDirectory()
        {
            return Environment.CurrentDirectory;
        }

        public String GetProcessId()
        {
            NowOutPut.OutputDebugString("[GetProcessId] BEGIN");
            Process currentProcess = Process.GetCurrentProcess();
            if (currentProcess != null)
            {
                NowOutPut.OutputDebugString(currentProcess.Id.ToString());
                return currentProcess.Id.ToString();
            }
            return String.Empty;
        }

        public String GetCurrentDateTime()
        {
            NowOutPut.OutputDebugString("[GetCurrentDateTime] BEGIN");
            DateTime today = DateTime.Now;
            if (today != null)
            {
                String strResult = String.Empty;
                strResult += today.Year.ToString() + "-" + today.Month.ToString() + "-" + today.Day.ToString() + ".";
                strResult += today.Hour.ToString() + "-" + today.Minute.ToString() + "-" + today.Second.ToString();
                NowOutPut.OutputDebugString(strResult);
                return strResult;
            }
            return String.Empty;
        }
        
        public bool isFolderPathExists(String path)
        {
            return Directory.Exists(path);
        }

        public bool CreateDirectory(String path)
        {
            DirectoryInfo info = Directory.CreateDirectory(path);
            return info.Exists;
        }
    }
}
