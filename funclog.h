#ifndef H_INCLUDED_FUNCLOG_1C01A2ED_E8B9_86BA_AC62_608DEEF33586AA
#define H_INCLUDED_FUNCLOG_1C01A2ED_E8B9_86BA_AC62_608DEEF33586AA

#define MAX_LOG_LEN   6144
#define LOGINDENT_LEN 1024
#define MAX_MSG_LEN        MAX_LOG_LEN - LOGINDENT_LEN
#define MAX_FUNCNAME_LEN   MAX_LOG_LEN - LOGINDENT_LEN

#define FUNCLOG_INDENT  //for dbglog strings  in functions
#define INDENTATION_SIZE 3


//////////////////////////////////////////////////////////////////////////

#include <map>
using namespace std;

#ifdef _WIN32
#	define __func__ __FUNCTION__
#endif


//////////////////////////////////////////////////////////////////////////

class FucLog
{
public:
    FucLog(char*);
    ~FucLog(void);
public:
    char m_szFuncname[MAX_FUNCNAME_LEN];
	static map<DWORD,UINT> gsm_layer;
	UINT m_layer;
};

// __func__   c99 standard defined
// __FUNCTION__ Windows defined,  but vc6 maybe does not support

#if defined(_DEBUG) || defined(DEBUG)
#	define INDENT_FUNCTION_INOUT_LOG	FucLog Log(__func__);
#else
#	define INDENT_FUNCTION_INOUT_LOG
#endif

#endif //H_INCLUDED_FUNCLOG_1C01A2ED_E8B9_86BA_AC62_608DEEF33586AA
