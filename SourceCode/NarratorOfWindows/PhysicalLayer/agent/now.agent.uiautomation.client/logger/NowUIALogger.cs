using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.utility;

namespace now.agent.uiautomation.client.logger
{
    public class NowUIALogger
    {
        private static NowUIALogger m_instance = null;
        private static String m_logConfigFileName = "\\logconfig.txt";

        private int m_logMode = NowLogMode.LOG_NONE;

        private String m_logFileFullPath = "";
        
        private NowUIALogger()
        {
            InitLogConfig();
        }

        /// <summary>
        /// Check environment and config file to log or not. If log, initial information form log file config
        /// </summary>
        private void InitLogConfig()
        {
            String strLogMode = NowUIAUtilities.GetInstance().GetEnvironmentVariableValue(NowUIAEnvironmentVariable.NOW_DEBUG_MODE);
            if (NowEnvVariable.ENV_VARIABLE_LOG_ENABLE.Equals(strLogMode))
            {
                InitLogFile();
                InitTraceInstance();
            }
            else
            {
                m_logMode = NowLogMode.LOG_NONE;
            }
        }

        /// <summary>
        /// Init log mode and log file (if log mode = file). Make sure environment variable log mode is 1
        /// </summary>
        /// <returns></returns>
        private void InitLogFile()
        {
            m_logMode = NowLogMode.LOG_NONE;
            String strLogConfigFilePath = String.Empty;

            //Get and check environment variable NOW_DEBUG_MODE 
            if (NowUIAUtilities.GetInstance().GetEnvironmentVariableValue(NowUIAEnvironmentVariable.NOW_DEBUG_MODE).Equals(NowEnvVariable.ENV_VARIABLE_LOG_ENABLE))
            {
                ////Get and check environment variable NOW_DEBUG_DIRECTORY
                String strDebugDirectory = NowUIAUtilities.GetInstance().GetEnvironmentVariableValue(NowUIAEnvironmentVariable.NOW_DEBUG_DIRECTORY);
                if (!strDebugDirectory.Equals(String.Empty))
                {
                    strLogConfigFilePath = strDebugDirectory + m_logConfigFileName;
                    
                    String line = String.Empty;
                    // Read the file and display it line by line.
                    StreamReader file = new StreamReader(strLogConfigFilePath);
                    if((line = file.ReadLine()) != null)
                    {
                        //Check log mode
                        if (line.Split('=')[0].ToLower().Equals("mode") && line.Split('=')[1].ToLower().Equals("debugview"))
                        {
                            m_logMode = NowLogMode.LOG_DEBUG_VIEW;
                        }//end-if
                        if (line.Split('=')[0].ToLower().Equals("mode") && line.Split('=')[1].ToLower().Equals("file"))
                        {
                            //Check and get log dir
                            if ((line = file.ReadLine()) != null)
                            {
                                if (line.Split('=')[0].ToLower().Equals("logdir"))
                                {
                                    String strLogFileName = NowUIAUtilities.GetInstance().GetProcessId() + "-" + NowUIAUtilities.GetInstance().GetCurrentDateTime() + ".txt";
                                    m_logMode = NowLogMode.LOG_FILE;
                                    m_logFileFullPath = line.Split('=')[1];
                                    m_logFileFullPath += "\\UIA_Agent\\";// +strLogFileName;
                                    if (NowUIAUtilities.GetInstance().CreateDirectory(m_logFileFullPath))
                                    {
                                        m_logFileFullPath += strLogFileName;
                                    }
                                    else
                                    {
                                        m_logMode = NowLogMode.LOG_NONE;
                                    }
                                }
                            }
                        }//end-if
                    }//end-if
                    file.Close();
                }//end-if
            }//end-if
        }//end-method

        /// <summary>
        /// init trace instance
        /// </summary>
        private void InitTraceInstance()
        {
            //NowOutPut.OutputDebugString("InitTraceInstance");
            //NowOutPut.OutputDebugString("Count" + Trace.Listeners.Count.ToString());
            if (Trace.Listeners.Count > 0)
            {
                //NowOutPut.OutputDebugString("Clear");
                Trace.Listeners.Clear();
            }
            if (m_logMode == NowLogMode.LOG_DEBUG_VIEW)
            {
                //NowOutPut.OutputDebugString("LOG_DEBUG_VIEW");
                Trace.Listeners.Add(new DefaultTraceListener());
                Trace.AutoFlush = true;
                //Trace.UseGlobalLock = false;
            }
            else if (m_logMode == NowLogMode.LOG_FILE)
            {
                //NowOutPut.OutputDebugString("LOG_FILE");
                Trace.Listeners.Add(new TextWriterTraceListener(m_logFileFullPath));
                Trace.AutoFlush = true;
            }
        }//end-method

        public static NowUIALogger GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIALogger();
            }
            return m_instance;
        }
        
        public void LogInfor(String format, params object[] args)
        {
            //NowOutPut.OutputDebugString("TraceInformation");
            Trace.TraceInformation(format, args);
        }

        public void LogError(String format, params object[] args)
        {
            Trace.TraceError(format, args);
        }

        public void LogWarning(String format, params object[] args)
        {
            Trace.TraceWarning(format, args);
        }
    }

    public class NowOutPut
    {
        [DllImport("kernel32.dll")]
        public static extern void OutputDebugString(string strOutPut);
    }
}
