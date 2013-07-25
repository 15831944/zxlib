///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#if defined(WIN32) || defined(_WINDOWS)
//#	include "StdAfx.h"
#	pragma warning(disable:4996)
#	include <Windows.h>
#endif


#include <string.h>
#include <stdio.h>

#include "zxlog.h"


///////////////////////////////////////////////////////////////////////////////

map<DWORD,UINT> FucLog::gsm_layer = map<DWORD,UINT>();

FucLog::FucLog(char* szFuncName)
{
	DWORD tid = GetCurrentThreadId();
	char szTid[20] = {0};
	sprintf(szTid, "[%d]", tid);

	if (gsm_layer.empty()){
		gsm_layer[tid]=0;
	}
	map<DWORD,UINT>::iterator itr;
	itr = gsm_layer.find(tid);
	if (itr == gsm_layer.end()){
		itr = gsm_layer.begin();
		gsm_layer[tid] = (*itr).second;
	}
	gsm_layer[tid] ++;
	m_layer = gsm_layer[tid];

    memset(m_szFuncname, 0, sizeof m_szFuncname);
	int msg_len = strlen(szFuncName) > MAX_FUNCNAME_LEN ? MAX_FUNCNAME_LEN-3 : strlen(szFuncName);
    strncpy(m_szFuncname, szFuncName, msg_len);

    char szAllLog[MAX_LOG_LEN] = {0};
    char szIndentLog[LOGINDENT_LEN-1] = {0};


    memset(szIndentLog, 0x20, sizeof(szIndentLog)-1);

	if(m_layer > 0 && INDENTATION_SIZE*(m_layer-1) < LOGINDENT_LEN){
    	szIndentLog[INDENTATION_SIZE*(m_layer-1)] = 0;
	}else{
    	szIndentLog[0] = 0;
	}

    strcpy(szAllLog, szIndentLog);
    strcat(szAllLog, "->");
    strcat(szAllLog, m_szFuncname);
	strcat(szAllLog, szTid);


#if defined(_WIN32) || defined(_WINDOWS)
    OutputDebugStringA(szAllLog);
#else
    printf(szAllLog);
#endif
}

//////////////////////////////////////////////////////////////////////////

FucLog::~FucLog(void)
{
	DWORD tid = GetCurrentThreadId();
	char szTid[20] = {0};
	sprintf(szTid, "[%d]", tid);

    char szAllLog[MAX_LOG_LEN] = {0};
    char szIndentLog[LOGINDENT_LEN] = {0};

    memset(szIndentLog, 0x20, LOGINDENT_LEN);
	if(INDENTATION_SIZE*(m_layer-1)<LOGINDENT_LEN){
		szIndentLog[INDENTATION_SIZE*(m_layer-1)]=0;
	}

    strcpy(szAllLog, szIndentLog);
    strcat(szAllLog, "<-");
    strcat(szAllLog, m_szFuncname);
	strcat(szAllLog, szTid);

	gsm_layer[tid]--;


#if defined(WIN32) || defined(_WINDOWS)
    OutputDebugStringA(szAllLog);
#else
    printf(szAllLog);
#endif

}
