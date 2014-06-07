#include "NowDeviceMouse.h"

int NowDeviceMouse::getClickType( const string& clickType )
{
	int nResult = NowDeviceMouse::MOUSE_LEFT;
	if (clickType.compare("left") == 0)
	{
		nResult = NowDeviceMouse::MOUSE_LEFT;
	}
	else if (clickType.compare("right") == 0)
	{
		nResult = NowDeviceMouse::MOUSE_RIGHT;
	}
	else if (clickType.compare("double") == 0)
	{
		nResult = NowDeviceMouse::MOUSE_DOUBLE;
	}
	return nResult;
}

void MouseMove (int x, int y )
{  
	double fScreenWidth    = ::GetSystemMetrics( SM_CXSCREEN )-1; 
	double fScreenHeight  = ::GetSystemMetrics( SM_CYSCREEN )-1; 
	double fx = x*(65535.0f/fScreenWidth);
	double fy = y*(65535.0f/fScreenHeight);
	INPUT  Input={0};
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1,&Input,sizeof(INPUT));
}

void LeftClick ( )
{  
	INPUT    Input={0};
	// left down 
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1,&Input,sizeof(INPUT));
	Sleep(50);
	// left up
	::ZeroMemory(&Input,sizeof(INPUT));
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
	::SendInput(1,&Input,sizeof(INPUT));
}

void RightClick ( )
{  
	INPUT    Input={0};
	// right down 
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
	::SendInput(1,&Input,sizeof(INPUT));

	// right up
	::ZeroMemory(&Input,sizeof(INPUT));
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
	::SendInput(1,&Input,sizeof(INPUT));
}

void NowDeviceMouse::clickMouse( int x, int y, int mouseType )
{
	SetCursorPos(x, y);

	//click
	if (mouseType == NowDeviceMouse::MOUSE_LEFT)
	{
		LeftClick();
	}
	else if (mouseType == NowDeviceMouse::MOUSE_RIGHT)
	{
		RightClick();
	}
	else if (mouseType == NowDeviceMouse::MOUSE_DOUBLE)
	{
		LeftClick();
		Sleep(50);
		LeftClick();
	}

}