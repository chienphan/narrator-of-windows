#include "NowService.h"
#include "NowDefine.h"
#include "NowConstant.h"
#include "NowLogger.h"

NowService* NowService::m_instance = NULL;

NowService::NowService(void)
{
}

NowService::~NowService(void)
{
}

NowService* NowService::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new NowService();
	}
	return m_instance;
}

std::string NowService::ParseState( int nState )
{
	string strState = "";
	if ( (nState & NOW_STATE_SELECTED) == NOW_STATE_SELECTED)
	{
		strState = strState + "is selected";
	}
	if ( (nState & NOW_STATE_COLLAPSED) == NOW_STATE_COLLAPSED)
	{
		strState = strState + " collapsed";
	}
	if ( (nState & NOW_STATE_EXPANDED) == NOW_STATE_EXPANDED)
	{
		strState = strState + " expanded";
	}
	if ( (nState & NOW_STATE_LEAF_NODE) == NOW_STATE_LEAF_NODE)
	{
		strState = strState + " leaf node";
	}
	if ( (nState & NOW_STATE_CHECKED) == NOW_STATE_CHECKED)
	{
		strState = strState + " checked";
	}
	if ( (nState & NOW_STATE_UNCHECKED) == NOW_STATE_UNCHECKED)
	{
		strState = strState + " unchecked";
	}
	return strState;
}

