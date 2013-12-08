#ifndef _NOW_DEVICE_H_
#define _NOW_DEVICE_H_

//#include "NowDefine.h"
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <direct.h>

#include <list>
#include <string>

#include <tchar.h>

#include <strsafe.h>
#pragma comment(lib, "User32.lib")

using namespace std;

#define DllExport   __declspec( dllexport )

class DllExport NowDevice
{
private:
	NowDevice(void);
	~NowDevice(void);
public:
	static long getCurrentProcessId();
	static string getCurrentDateTime();
	static string getCurrentDirectory();
	static list<string>* getAllFilesInDirectory(const string& strDirectory, const string& strExtension);
};

#endif