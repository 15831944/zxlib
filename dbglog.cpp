//////////////////////////////////////////////////////////////////////////////
//attention:
//DBGLOG_FUNC must write after FucLog

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


#ifdef _WIN32
//#	include "stdafx.h"
#	pragma warning(disable:4996)
#	include <windows.h>  //OutputDebugStringA()
#	include <windowsx.h>
#endif

#include "zxlog.h"

//////////////////////////////////////////////////////////////////////////////
void DBGLOG_ARGLIST( const char * fmt, ... )
{
	DWORD tid = GetCurrentThreadId();

	char szAlllog[MAX_LOG_LEN] = {0};
	char saMsglog[MAX_MSG_LEN] = {0};
	char szIndentLog[LOGINDENT_LEN] = {0};

	va_list args;
	va_start( args, fmt );
	vsprintf(saMsglog,fmt,args);
	va_end(args);

	memset(szIndentLog, 0x20, sizeof(szIndentLog));
	
#if defined(FUNCLOG_INDENT) && defined(INDENTATION_SIZE)
	if (FucLog::gsm_layer.empty()){
		szIndentLog[0]=0;
	}else{
		if(FucLog::gsm_layer[tid]>0 && FucLog::gsm_layer[tid]*INDENTATION_SIZE<LOGINDENT_LEN)
			szIndentLog[INDENTATION_SIZE*FucLog::gsm_layer[tid]]=0;
		else
			szIndentLog[0]=0;
	}
#else
	szIndentLog[0]=0;
#endif

	strcpy(szAlllog, szIndentLog);
	strcat(szAlllog, saMsglog);
 
#if defined(_WIN32) || defined(_WINDOWS)
    OutputDebugStringA(szAlllog);
#else
    printf(szAllLog);
#endif
	
}

void DBGLOG_ARGLISTW( const wchar_t * fmt, ... )
{  
	DWORD tid = GetCurrentThreadId();

	wchar_t szAllLog[MAX_LOG_LEN] = {0};
	wchar_t szMsgLog[MAX_MSG_LEN] = {0};
	wchar_t szIndentLog[LOGINDENT_LEN] = {0};

	va_list args;
	va_start( args, fmt );
	vswprintf(szMsgLog,fmt,args);
	va_end(args);

	for (int i=0; i<LOGINDENT_LEN && wcslen(szIndentLog)<LOGINDENT_LEN-2; i++){
		wcscat(szIndentLog, L" ");
	}

#if defined(FUNCLOG_INDENT) && defined(INDENTATION_SIZE)
	if (FucLog::gsm_layer.empty()){
		szIndentLog[0]=0;
	}else{
		if(FucLog::gsm_layer[tid]>0 && FucLog::gsm_layer[tid]*INDENTATION_SIZE<LOGINDENT_LEN)
			szIndentLog[INDENTATION_SIZE*FucLog::gsm_layer[tid]]=0;
		else
			szIndentLog[0]=0;
	}
#else
	szIndentLog[0]=0;
#endif

	wcscpy(szAllLog, szIndentLog);
	wcscat(szAllLog, szMsgLog);

#if defined(_WIN32) || defined(_WINDOWS)
	OutputDebugStringW(szAllLog);
#else
	wprintf(szAllLog);
#endif


}


void DBGLOG_HEXSZ(unsigned char* der, unsigned long cbder)
{
	if(!der)
		return;

	char* pStr = 0;

	unsigned long szlen = cbder*2+(cbder-cbder%32)/32+10;
	pStr = (char*)malloc(szlen);
	if(!pStr)
		return;

	memset(pStr, 0, szlen);

	for(unsigned long m=0,n=0; n<cbder; n++,m++)
	{
		sprintf(&pStr[m*2], "%2X", der[n]);

		if(n>0 && n%32==0){
			sprintf(&pStr[(m+1)*2],"\n ");
			m++;
		}
	}


#if defined(_WIN32) || defined(_WINDOWS)
    OutputDebugStringA(pStr);
#else
    printf(pStr);
#endif

    free(pStr);
}



