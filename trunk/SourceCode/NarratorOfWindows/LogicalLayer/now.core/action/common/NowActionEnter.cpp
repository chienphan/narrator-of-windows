#include "NowActionEnter.h"
#include "NowStorage.h"
#include "NowLogger.h"
#include "NowStringProcessor.h"
#include "NowDeviceMouse.h"
#include "NowDeviceKeyboard.h"
#include "NowUtility.h"

NowActionEnter::NowActionEnter(void)
{
}

NowActionEnter::~NowActionEnter(void)
{
}

//enter=<window_name>|<control_name>|<content>
NOW_RESULT NowActionEnter::prepareArguments(vector<wstring>* argumnents)
{
	NOW_RESULT nResult = NOW_FALSE;
	m_strWindowName = NowStringProcessor::wstringTostring(argumnents->at(1));
	m_strControlname = NowStringProcessor::wstringTostring(argumnents->at(2));
	m_strContent = argumnents->at(3);
	nResult = NowStorage::getInstance()->getWindow(m_strWindowName.c_str(), m_window);
	if (NOW_SUCCEED(nResult))
	{
		nResult = NowStorage::getInstance()->getControl(m_strControlname.c_str(), m_control);
	}
	return nResult;
}

NOW_RESULT NowActionEnter::doAction()
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
				NowDeviceMouse::clickMouse(left + width / 2, top + height / 2, NowDeviceMouse::getClickType("left"));
				
				//NowDeviceKeyboard::sendKey(L"^a");
				//NowDeviceKeyboard::sendKey(L"{DEL}");
				NowDeviceKeyboard::sendKey(m_strContent);
			}
		}
	}
	return nResult;
}
