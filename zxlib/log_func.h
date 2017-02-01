//////////////////////////////////////////////////////////////////////////////
#ifndef H_INCLUDED_ZLOG_711F5F5E_A54D_D1D0_C9B6_5F611A45B9F9C2
#define H_INCLUDED_ZLOG_711F5F5E_A54D_D1D0_C9B6_5F611A45B9F9C2

// author: zxlooong@gmail.com
// data  : 2012-11-21
// up    : 2013-01-09 add support muti thread log out.


//attention:
// log msg must write after FucLog

// ע�� ��־Ҫ�ں�����־��߳��֣�������־�����������⡣
// ע�� ���ע��ӿں����в�������־����������ע��ʧ�ܣ�Ŀǰû�в鵽ԭ��
////////////////////////////////////////////////////////////////////////////

#define MAX_LOG_LEN   6144
#define LOGINDENT_LEN 1024
#define MAX_MSG_LEN        MAX_LOG_LEN - LOGINDENT_LEN
#define MAX_FUNCNAME_LEN   MAX_LOG_LEN - LOGINDENT_LEN




#include "funclog.h" //�������Ҫ����������������Ҫ��c���룬ע�ʹ��У�
#include "dbglog.h"


#endif // H_INCLUDED_ZLOG_711F5F5E_A54D_D1D0_C9B6_5F611A45B9F9C2
