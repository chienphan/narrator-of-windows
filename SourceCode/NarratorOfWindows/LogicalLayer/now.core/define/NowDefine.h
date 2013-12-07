#ifndef _NOW_DEFINE_H_
#define _NOW_DEFINE_H_

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <windows.h>

//declaration 
class INowPlugin;
class NowControl;

//using define
using namespace std;

//constant define
#define NOW_OK		0
#define NOW_FALSE	-1
#define NOW_MAXLENGTH 256
#define NOW_SUCCEED(x) (x>=0)
//#define CREATE_WSTRING(x) L"x"

//type define
typedef int NOW_RESULT;
typedef INowPlugin* (__cdecl *NOW_PROC)(); 
//typedef INowPlugin* (__cdecl *MYPROC)(LPWSTR); 


#endif // _NOW_DEFINE_H_

