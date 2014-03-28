
//
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_)
#define AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

//#include "stdafx.h"
#include <vector>
#include <string>
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

tstring __cdecl st2Tstring(std::string str);
std::string __cdecl ts2String(tstring tstr);
tstring errString(int errCode);

#endif // !defined(AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_)
