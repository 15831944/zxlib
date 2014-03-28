
//////////////////////////////////////////////////////////////////////
//#include "stdafx.h"
#include <assert.h>
#include "StrTools.h"
#include "MemTools.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


tstring __cdecl st2Tstring(std::string str)
{
    MemTools::CA2TCharBuf a2tbuf(str.c_str());

    tstring ret = a2tbuf.ptr;
    return ret;
}


std::string  __cdecl ts2String(tstring tstr)
{
    MemTools::CT2ACharBuf t2abuf(tstr.c_str());
    std::string ret = t2abuf.ptr;

    return ret;
}

tstring errString(int errCode)
{
    tstrstream ss;
    ss.flags(std::ios::internal | std::ios::hex | std::ios::showbase);
    ss.width(8);
    ss.fill('0');
    ss << errCode;

    return ss.str();
}




//////////////////////////////////////////////////////////////////////////
