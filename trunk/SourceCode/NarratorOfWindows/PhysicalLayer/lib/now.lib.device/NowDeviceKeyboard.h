#ifndef _NOW_DEVICE_KEYBOARD_H
#define _NOW_DEVICE_KEYBOARD_H

#include "NowDefine.h"

class DllExport NowDeviceKeyboard
{

public:
	static void sendKey(wstring content);
	static void sendKey(string content);
};


#endif