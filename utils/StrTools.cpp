
//////////////////////////////////////////////////////////////////////
//#define _CRT_SECURE_NO_WARNINGS
#include "../stdafx.h"
#include <assert.h>
#include "StrTools.h"
#include "MemTools.h"



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
namespace StrTools
{

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
        ss.flags(std::ios::internal | std::ios::hex | std::ios::showbase | std::ios::uppercase);
        ss.width(10);
        ss.fill('0');
        ss << errCode;

        return ss.str();
    }

    tstring hexString(uchar* pData, int len)
    {
        MemTools::CTCharBuf  buf(len * 2);
        
        for (int i = 0; i < len; i++){
             _stprintf(&(buf.ptr)[i*2], _T("%02x"), pData[i]);
        }

        tstring str = buf.ptr;

        return str;
    }
}  // namespace StrTools end;

//////////////////////////////////////////////////////////////////////////