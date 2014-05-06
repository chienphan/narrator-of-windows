#ifndef _NOW_EDIT_UIA_H
#define _NOW_EDIT_UIA_H

#include "nowcontrol_uia.h"
class NowEdit_UIA :
	public NowControl_UIA
{
public:
	NowEdit_UIA(string strSignature, string strControlType);
	~NowEdit_UIA(void);

	virtual NOW_RESULT setValue( const wstring& wstrValue );

};

#endif


