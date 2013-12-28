set PROJECT_DIR=D:\Duan\PhysicalLayer\agent\now.agent.uiautomation.client
set OUT_DIR=D:\Duan\bin\Debug_32
set NET_REFERENCE_DIR=C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.0
set NET_FRAMEWORK_DIR=C:\Windows\Microsoft.NET\Framework\v4.0.30319

"%NET_FRAMEWORK_DIR%\csc.exe" /debug /target:module /reference:"%NET_REFERENCE_DIR%\UIAutomationClient.dll" /reference:"%NET_REFERENCE_DIR%\UIAutomationTypes.dll" /reference:"%NET_REFERENCE_DIR%\WindowsBase.dll" /out:%OUT_DIR%\now.agent.uiautomation.client.netmodule %PROJECT_DIR%\*.cs
