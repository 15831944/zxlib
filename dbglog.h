//////////////////////////////////////////////////////////////////////////////
#ifndef H_INCLUDED_DBG_LOG_BD0FC3E9_4D2B_4A51_8935_01522932B969
#define H_INCLUDED_DBG_LOG_BD0FC3E9_4D2B_4A51_8935_01522932B969
//attention:
//DBGLOG_FUNC must write after FucLog

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


#ifdef _WIN32
#	include <windows.h>    //OutputDebugStringA()
#	include <windowsx.h>
#endif

#include "funclog.h"

//////////////////////////////////////////////////////////////////////////////
void DBGLOG_ARGLIST( const char * fmt, ... );
void DBGLOG_ARGLISTW( const wchar_t * fmt, ... );
void DBGLOG_HEXSZ( unsigned char* der, unsigned long cbder );
//static void DBGLOG_FUNC( wchar_t * fmt, ... );


#if defined(UNICODE)
#	define  DBGLOG	DBGLOGW
#else
#	define	DBGLOG	DBGLOGA
#endif


#if defined(_DEBUG) || defined(DEBUG)
#	define DBGLOGA(fmt)			DBGLOG_ARGLIST fmt
#	define DBGLOGW(fmt)			DBGLOG_ARGLISTW fmt
#	define DBGLOGHX(fmt)		DBGLOG_HEXSZ fmt
// TODO: te	st DBGLOGEX, there maybe some problem;
#	define DBGLOGEX(fmt)		DBGLOG_ARGLIST##( fmt ##)
#	define DBGLOGHXEX(fmt)		DBGLOG_HEXSZ##( fmt ##)
#else
#	define DBGLOGA(fmt)
#	define DBGLOGW(fmt)	
#	define DBGLOGEX(fmt)
#	define DBGLOGHX(fmt)
#	define DBGLOGHXEX(fmt)
#endif //_DEBUG





#endif // H_INCLUDED_DBG_LOG_BD0FC3E9_4D2B_4A51_8935_01522932B969




