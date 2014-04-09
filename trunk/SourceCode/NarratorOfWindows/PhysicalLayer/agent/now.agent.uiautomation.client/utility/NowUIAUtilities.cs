using System;
using System.Diagnostics;
using System.IO;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client.utility
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

        /// <summary>
        /// Get value of environment variable
        /// </summary>
        /// <param name="strVariable">the environment variable</param>
        /// <returns>the value</returns>
        public String GetEnvironmentVariableValue(String strVariable)
        {
            return Environment.GetEnvironmentVariable(strVariable);
        }

        /// <summary>
        /// Get path of current directory of this process
        /// </summary>
        /// <returns>path of directory</returns>
        public String GetCurrentDirectory()
        {
            return Environment.CurrentDirectory;
        }

        /// <summary>
        /// Get process ID
        /// </summary>
        /// <returns>process ID at String</returns>
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

        /// <summary>
        /// Get current datetime
        /// </summary>
        /// <returns>the current datetime at String with format YYYY-MM-DD.HH-mm-ss</returns>
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
        
        /// <summary>
        /// Check the path is exist
        /// </summary>
        /// <param name="path"></param>
        /// <returns></returns>
        public bool isFolderPathExists(String path)
        {
            return Directory.Exists(path);
        }

        /// <summary>
        /// Create directory with the path
        /// </summary>
        /// <param name="path"></param>
        /// <returns></returns>
        public bool CreateDirectory(String path)
        {
            DirectoryInfo info = Directory.CreateDirectory(path);
            return info.Exists;
        }

        public bool IsRegExpPattern(String strPattern)
        {
            if (strPattern.StartsWith("{") && strPattern.EndsWith("}"))
            {
                return true;
            }
            return false;
        }

        public string TrimRegExpPattern(string strTitleWindow)
        {
            String result = strTitleWindow.TrimStart(new char[] { '{' });
            result = result.TrimEnd(new char[] { '}' });
            return result;
        }
    }
}
