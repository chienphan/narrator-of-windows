#ifndef _NOW_CONTROL_UIA_H_
#define _NOW_CONTROL_UIA_H_

#include "NowDefine.h"
#include "INowControl.h"

class NowControl_UIA : public INowControl
{
private:

protected:
	string m_strSignature;
	string m_strControlType;

public:
	NowControl_UIA(string strSignature, string strControlType);

	~NowControl_UIA(void);

	virtual NOW_RESULT getControlType( string& strControlType );

	virtual NOW_RESULT getCaption( wstring& wstrCaption );

	virtual NOW_RESULT getHelpText( wstring& wstrHelpText );

	virtual NOW_RESULT getParent( INowControl*& ctrParent );

	virtual NOW_RESULT getChildren( list<INowControl*>& lstChildren );

	virtual NOW_RESULT getState( int& nState );

	virtual NOW_RESULT getSignature( string& strSignature );

	virtual NOW_RESULT getNowClass( string& strNowClass );

	virtual NOW_RESULT getUIProperty( const string& strPropName, wstring& strValue );

};

#endif//_NOW_CONTROL_UIA_H_