//////////////////////////////////////////////////////////////////////////////
#ifndef H_INCLUDED_ZLOG_711F5F5E_A54D_D1D0_C9B6_5F611A45B9F9C2
#define H_INCLUDED_ZLOG_711F5F5E_A54D_D1D0_C9B6_5F611A45B9F9C2

// author: zxlooong@gmail.com
// data  : 2012-11-21
// up    : 2013-01-09 add support muti thread log out.


//attention:
// log msg must write after FucLog

// 注意 日志要在函数日志后边出现，否则日志缩进会会出问题。
// 注意 插件注册接口函数中不能有日志输出，否则会注册失败，目前没有查到原因。
////////////////////////////////////////////////////////////////////////////

#define MAX_LOG_LEN   6144
#define LOGINDENT_LEN 1024
#define MAX_MSG_LEN        MAX_LOG_LEN - LOGINDENT_LEN
#define MAX_FUNCNAME_LEN   MAX_LOG_LEN - LOGINDENT_LEN




#include "funclog.h" //如果不需要函数缩进，或者需要纯c编译，注释此行；
#include "dbglog.h"


#endif // H_INCLUDED_ZLOG_711F5F5E_A54D_D1D0_C9B6_5F611A45B9F9C2
