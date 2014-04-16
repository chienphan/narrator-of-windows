#ifndef _NOW_DEFINE_H_
#define _NOW_DEFINE_H_

#include <tchar.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <tchar.h>

//#include "NowDevice.h"
#include "NowConstant.h"

//declaration 
class INowPlugin;
class INowControl;
class INowWindow;
class INowAction;

//using define
using namespace std;

//type define
typedef int NOW_RESULT;
typedef INowPlugin* (__cdecl *NOW_PROC)(); 
//typedef INowPlugin* (__cdecl *MYPROC)(LPWSTR); 

typedef vector<INowPlugin*>* NowListPlugins;
typedef map<string, INowWindow*> NowMapWindow;
typedef map<string, INowControl*> NowMapControl;

#define DllExport   __declspec( dllexport )

#endif // _NOW_DEFINE_H_

