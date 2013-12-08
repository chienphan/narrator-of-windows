#ifndef _NOW_CONTROL_UIA_H_
#define _NOW_CONTROL_UIA_H_

#include "NowDefine.h"
#include "INowControl.h"

class NowControl_UIA :
	public INowControl
{
public:
	NowControl_UIA(void);

	~NowControl_UIA(void);

	virtual NOW_RESULT getControlType( string& strControlType );

	virtual NOW_RESULT getCaption( wstring& wstrCaption );

	virtual NOW_RESULT getHelpText( wstring& wstrHelpText );

	virtual NOW_RESULT getParent( INowControl*& ctrParent );

	virtual NOW_RESULT getChildren( list<INowControl*>& lstChildren );

	virtual NOW_RESULT getState( int& nState );

};

#endif//_NOW_CONTROL_UIA_H_