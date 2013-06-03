
//
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_)
#define AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "stdafx.h"
#include <vector>
#include <string>
#include <tchar.h>
#include <windows.h>
#include <WinCrypt.h>



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
#       define tstrstream std::stringstream
#   else
#       define tstrstream std::wstringstream
#   endif
#endif

#if !defined(XENCODETYPE)
#   define XENCODETYPE			X509_ASN_ENCODING | PKCS_7_ASN_ENCODING
#endif

typedef unsigned char uchar;
typedef unsigned long ulong;
////////////////////////////////////////////////////////////////////////
namespace MemTools
{
	class  CByteBuf
	{
	public:
		unsigned char * ptr;
		CByteBuf();
		CByteBuf(int ilen);
		~CByteBuf();
	};

	class  CIntBuf
	{
	public:
		int * ptr;
		CIntBuf();
		CIntBuf(int ilen);
		~CIntBuf();
	};


	class  CTCharBuf
	{
	public:
		TCHAR *ptr;
		CTCharBuf(int len);
		~CTCharBuf();
	};

	class  CW2ACharBuf
	{
	public:
		char *ptr;
		CW2ACharBuf(const wchar_t* lp);
		~CW2ACharBuf();
	};

	class CW2TCharBuf
	{
	public:
		TCHAR* ptr;
		CW2TCharBuf(const wchar_t* lp);
		~CW2TCharBuf();
	};

	class  CA2WCharBuf
	{
	public:
		WCHAR *ptr;
		CA2WCharBuf(const char* lp);
		~CA2WCharBuf();
	};	

	class  CA2TCharBuf
	{
	public:
		TCHAR *ptr;
		CA2TCharBuf(const char* lp);
		~CA2TCharBuf();
	};

	class  CT2WCharBuf
	{
	public:
		wchar_t *ptr;
		CT2WCharBuf(const TCHAR* lp);
		~CT2WCharBuf();
	};

	class  CT2ACharBuf
	{
	public:
		char *ptr;
		CT2ACharBuf(const TCHAR* lp);
		~CT2ACharBuf();
	};

	class  CUT82TCharBuf
	{
	public:
		TCHAR *ptr;
		CUT82TCharBuf(const char* lp);
		~CUT82TCharBuf();
	};

	class  CT2UTF8CharBuf
	{
	public:
		char *ptr;
		CT2UTF8CharBuf(const TCHAR* lp);
		~CT2UTF8CharBuf();
	};
	//////////////////////////////////////////////////////////////////////////

	tstring __cdecl st2Tstring(std::string str);
	std::string __cdecl ts2String(tstring tstr);

}


#endif // !defined(AFX_MEMTOOLS_H__C3BE95F2_81F0_4B34_9F2C_EC210DACBFAC__INCLUDED_)
