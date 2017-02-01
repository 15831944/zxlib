
//
////////////////////////////////////////////////////////////////////////////////
// 
// #if !defined(AFX_STRTOOLS_H__83F8597D_DA33_45B1_A081_98026EA4D0E4__INCLUDED_)
// #define AFX_STRTOOLS_H__83F8597D_DA33_45B1_A081_98026EA4D0E4__INCLUDED_

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "str_inc.h"


namespace StrTools
{

    tstring errString(int errCode);
    tstring hexString(uchar* pData, int len);

	tstring __cdecl str2tstr(std::string str);
	astring __cdecl tstr2str(tstring tstr);
	tstring __cdecl bstr2tstr(BSTR bstr);
	BSTR tstr2bstr(tstring str);

}


//#endif // !defined(AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_)
