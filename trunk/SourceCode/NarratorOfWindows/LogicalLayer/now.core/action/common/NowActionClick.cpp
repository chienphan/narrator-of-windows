#include "NowActionClick.h"
#include "NowStorage.h"
#include "NowLogger.h"
#include "NowUtility.h"
#include "NowDeviceMouse.h"

NowActionClick::NowActionClick(void)
{
	m_control = NULL;
	m_window = NULL;
}


NowActionClick::~NowActionClick(void)
{

}

//click=<window_name>|<control_name>|<click_type>
NOW_RESULT NowActionClick::prepareArguments(vector<string>* argumnents)
{
	NOW_RESULT nResult = NOW_FALSE;
	m_strWindowName = argumnents->at(1);
	m_strControlname = argumnents->at(2);
	m_clickType = argumnents->at(3);
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
	Sleep(500);
	string strValue;// = "";
	if (m_control != NULL)
	{
		nResult = m_control->getProperty(NOW_PROP_BOUNDING_RECTANGLE, strValue);

		if (NOW_SUCCEED(nResult))
		{
			vector<string>* vec = NowUtility::split(strValue, NOW_CHAR_COMMA);
			if (vec != NULL)
			{
				int left = 0;
				int top = 0;
				int width = 0;
				int height = 0;
				NowUtility::getRectData(vec, left, top, width, height);
				NowDeviceMouse::clickMouse(left + width / 2, top + height / 2, NowDeviceMouse::getClickType(m_clickType));
			}
		}
	}
	return NOW_OK;
}
