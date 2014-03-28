
//
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRTOOLS_H__83F8597D_DA33_45B1_A081_98026EA4D0E4__INCLUDED_)
#define AFX_STRTOOLS_H__83F8597D_DA33_45B1_A081_98026EA4D0E4__INCLUDED_

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

//#include "stdafx.h"
#include <vector>
#include <string>
#include <sstream>
#include <tchar.h>
#include <windows.h>



//////////////////////////////////////////////////////////////////////////
#if !defined(tstring)
#   if defined(UNICODE) || defined(_UNICODE)
#       define tstring std::wstring 
#   else
#       define tstring std::string
#   endif
#endif

#if !defined(tstrstream)
#   if defined(UNICODE) || defined(_UNICODE)
#       define tstrstream std::wstringstream
#   else
#       define tstrstream std::stringstream
#   endif
#endif

typedef unsigned char uchar;
typedef unsigned long ulong;

namespace StrTools
{
    tstring __cdecl st2Tstring(std::string str);
    std::string __cdecl ts2String(tstring tstr);
    tstring errString(int errCode);
    tstring hexString(uchar* pData, int len);

}


#endif // !defined(AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_)
