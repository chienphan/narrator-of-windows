#include "NowMatching.h"
#include "INowWindow.h"
#include "NowDefine.h"

NowMatching* NowMatching::m_instance = 0;

NowMatching::NowMatching(void)
{
}


NowMatching::~NowMatching(void)
{
}

NowMatching* NowMatching::getInstance()
{
	if (m_instance == 0)
	{
		m_instance = new NowMatching();
	}
	return m_instance;
}

NOW_RESULT NowMatching::matchWindow( const char* szWindowTitle, INowWindow*& pWindow )
{
	return NOW_OK;
}


