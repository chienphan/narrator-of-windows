#include "NowActionClick.h"


NowActionClick::NowActionClick(void)
{
}


NowActionClick::~NowActionClick(void)
{
}

NOW_RESULT NowActionClick::prepareArguments(vector<string>* argumnents)
{
	printf("NowActionClick::prepareArguments\n");
	return NOW_OK;
}

NOW_RESULT NowActionClick::doAction()
{
	printf("NowActionClick::doAction\n");
	return NOW_OK;
}
