#include "NowActionTypeKey.h"


NowActionTypeKey::NowActionTypeKey(void)
{
}


NowActionTypeKey::~NowActionTypeKey(void)
{
}

NOW_RESULT NowActionTypeKey::prepareArguments(vector<string>* argumnents)
{
	printf("NowActionTypeKey::prepareArguments\n");
	return NOW_OK;
}

NOW_RESULT NowActionTypeKey::doAction()
{
	printf("NowActionTypeKey::doAction\n");
	return NOW_OK;
}
