#ifndef _NOW_DEFINE_H_
#define _NOW_DEFINE_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

//#include "NowDevice.h"
#include "NowConstant.h"

//declaration 
class INowPlugin;
class INowControl;

//using define
using namespace std;

//type define
typedef int NOW_RESULT;
typedef INowPlugin* (__cdecl *NOW_PROC)(); 
//typedef INowPlugin* (__cdecl *MYPROC)(LPWSTR); 

typedef vector<INowPlugin*>* NowListPlugins;

#endif // _NOW_DEFINE_H_

