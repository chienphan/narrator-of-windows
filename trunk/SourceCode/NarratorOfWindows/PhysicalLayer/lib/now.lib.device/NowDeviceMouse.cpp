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

void NowDeviceMouse::lineBresenham(int x1, int y1, int x2, int y2){
	int c2, c, Dx, Dy, x, y;
	Dx = abs(x2 - x1);
	Dy = abs(y2 - y1);
	c = Dx - Dy;
	c2 = 2*c;
	x = x1;
	y = y1;

	int x_unit = 1, y_unit = 1;

	if (x2 - x1 < 0)
		x_unit = -x_unit;
	if (y2 - y1 < 0)
		y_unit = -y_unit;

	MouseMove(x, y);
	//putpixel(x, y, colorGreen);

	if (x1 == x2)   // duong thang dung
	{
		while (y != y2)
		{
			Sleep(10);
			//delay(DELAY);
			y += y_unit;
			MouseMove(x, y);
			//putpixel(x, y, colorGreen);
		}
	}

	else if (y1 == y2)  // duong ngang
	{
		while (x != x2)
		{
			Sleep(10);
			//delay(DELAY);
			x += x_unit;
			MouseMove(x, y);
			//putpixel(x, y, colorGreen);
		}
	}

	else if (x1 != x2 && y1 != y2)  // duong xien
	{
		while(x != x2+1)
		{
			Sleep(10);
			//delay(DELAY);
			c2 =2*c;
			if (c2 > -Dy)    
			{
				c = c - Dy; 
				x = x + x_unit;
			}
			if (c2 < Dx) 
			{
				c = c + Dx; 
				y = y + y_unit; 
			}
			MouseMove(x, y);
			//putpixel(x, y, colorGreen);
		}
	}
	MouseMove(x2, y2);
}

void NowDeviceMouse::moveAndClickMouse( int x1, int y1, int x2, int y2, int mouseType )
{
	lineBresenham(x1, y1, x2, y2);
	
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
