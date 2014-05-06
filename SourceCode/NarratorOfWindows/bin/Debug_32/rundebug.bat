REM Copy all jar libraries into debug directory...
set JAVA_BUILD_DIRECTORY=C:\narrator-of-windows\SourceCode\NarratorOfWindows\ProductLayer\now.window.lib\dist
set DEBUG_DIRECTORY=C:\narrator-of-windows\SourceCode\NarratorOfWindows\bin\Debug_32
if exist %JAVA_BUILD_DIRECTORY% xcopy %JAVA_BUILD_DIRECTORY% %DEBUG_DIRECTORY% /E /Y

REM Call jar entry point...
C:\narrator-of-windows\SourceCode\NarratorOfWindows\jre\jre1.7.0_45\bin\java.exe -jar "now.window.lib.jar"

pause