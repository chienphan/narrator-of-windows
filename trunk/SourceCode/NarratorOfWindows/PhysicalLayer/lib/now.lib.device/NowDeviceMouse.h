#ifndef _NOW_DEVICE_MOUSE_H_
#define _NOW_DEVICE_MOUSE_H_

#include "NowDefine.h"

class DllExport NowDeviceMouse
{
public:
	enum mouseType{
		MOUSE_LEFT = 0,
		MOUSE_RIGHT,
		MOUSE_DOUBLE
	};

	static int getClickType(const string& clickType);
	static void clickMouse(int x, int y, int mouseType);

};

#endif

