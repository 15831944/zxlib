// zxlib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StrTools.h"


#include "zxlog.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

    uchar aa[4] = { 1, 2, 3, 4 };
    char* certb64 = "MIICazCCAdagAwIBAgIQAeAlpxe+CyODO8uZgiBPATALBgkqhkiG9w0BAQQwSzEVMBMGA1UECgwM5aSp5aiB6K+a5L+hMRUwEwYDVQQLDAznoJTlj5HkuK3lv4MxGzAZ BgNVBAMMEua1i+ivlUNB6K+B5LmmLVpIUzAeFw0wODA0MDEwMDAwMDBaFw0xMDA0 MDEyMzU5NTlaMF0xFTATBgNVBAoMDOWkqeWogeivmuS/oTEVMBMGA1UECwwM5oqA 5pyv5Lit5b+DMS0wKwYDVQQDDCTku6PnoIHnrb7lkI0o5aSp5aiB6K+a5L+hLea1 i+ivleeUqCkwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAKJuYasGLwYwuT76 GIqX2yYS91rqMRLSR5/FwxKecQUUeh+KPIiAuS28v3+NXG2ICGPXHQUR1+EEFyQ0 HRAPzN8lMisfoynClXKVEE+kxCsfRNW3bGgXyojGpxjjcC0gSmSHx/BjCIJEeOP4 1AUfQPoeAUqPbMiuXlWyFW2Tj3BLAgMBAAGjQjBAMAkGA1UdEwQCMAAwCwYDVR0P BAQDAgeAMBMGA1UdJQQMMAoGCCsGAQUFBwMDMBEGCWCGSAGG+EIBAQQEAwIEEDAL BgkqhkiG9w0BAQQDgYEAgLJadiTcN/UOuj2LTXiYcXBRlzVlT4n16BcjdQbXDkxv 7TlUKQSrGA0Eb8FSHi0pbbwpeL/rwUuNuy9NHT7sMgJVFWHnbJdg/L6v4wZ6lN1M e+e2i6dnZ5jgqFIPFjTENcJYEZ6ERe8nS9gwwe7/Tkzn7Xq+t+Rir4NHOegWRmc=";

    tstring  str = StrTools::hexString((uchar*)certb64, strlen(certb64));

    wcout << str << endl;

    int  ierr = 9935;

    wcout << StrTools::errString(ierr) << endl;


    DBGLOG_DUMP_PROCID();

    return 0;
}

