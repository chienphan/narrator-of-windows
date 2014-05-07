#include "NowActionClick.h"
#include "NowStorage.h"
#include "NowLogger.h"
#include "NowUtility.h"
#include "NowDeviceMouse.h"
#include "NowStringProcessor.h"

NowActionClick::NowActionClick(void)
{
	m_control = NULL;
	m_window = NULL;
	m_strWindowName = "";
	m_strControlname = "";
	m_clickType = "";
}

NowActionClick::~NowActionClick(void)
{

}

//click=<window_name>|<control_name>|<click_type>|<x(optional)>|<y(optional)>
NOW_RESULT NowActionClick::prepareArguments(vector<wstring>* argumnents)
{
	NOW_RESULT nResult = NOW_FALSE;

	m_x = 0;
	m_y = 0;

	m_strWindowName = NowStringProcessor::wstringTostring(argumnents->at(1));
	m_strControlname = NowStringProcessor::wstringTostring(argumnents->at(2));
	m_clickType = NowStringProcessor::wstringTostring(argumnents->at(3));

	if (argumnents->size() == 6)
	{
		string strX = NowStringProcessor::wstringTostring(argumnents->at(4));
		string strY = NowStringProcessor::wstringTostring(argumnents->at(5));

		if (!strX.empty() && !strY.empty())
		{
			m_x = atoi(strX.c_str());
			m_y = atoi(strY.c_str());
			NowLogger::getInstance()->LogAString("[NowActionClick::prepareArguments]");
			NowLogger::getInstance()->LogInt(m_x);
			NowLogger::getInstance()->LogInt(m_y);
		}
	}
	

	nResult = NowStorage::getInstance()->getWindow(m_strWindowName.c_str(), m_window);
	if (NOW_SUCCEED(nResult))
	{
		nResult = NowStorage::getInstance()->getControl(m_strControlname.c_str(), m_control);
	}
	return nResult;
}

NOW_RESULT NowActionClick::doAction()
{
	NOW_RESULT nResult = NOW_FALSE;

	if (m_window != NULL)
	{
		m_window->bringToTop();
	}
	Sleep(100);
	string strValue;// = "";
	if (m_control != NULL)
	{
		nResult = m_control->getProperty(NOW_PROP_BOUNDING_RECTANGLE, strValue);
		if (NOW_SUCCEED(nResult))
		{
			vector<string>* vec = NowStringProcessor::split(strValue, NOW_CHAR_COMMA);
			if (vec != NULL)
			{
				int left = 0;
				int top = 0;
				int width = 0;
				int height = 0;
				NowUtility::getRectData(vec, left, top, width, height);

				PPOINT point = new POINT();
				if (GetCursorPos(point) && left != 0 && top != 0)
				{
					if (m_x > 0 && m_y > 0)
					{
						NowDeviceMouse::moveAndClickMouse(point->x, point->y, left + m_x, top + m_y, NowDeviceMouse::getClickType(m_clickType));
					}
					else
					{
						NowDeviceMouse::moveAndClickMouse(point->x, point->y, left + width / 2, top + height / 2, NowDeviceMouse::getClickType(m_clickType));
					}
				}
				delete point;
			}
			delete vec;
		}
	}
	return nResult;
}
