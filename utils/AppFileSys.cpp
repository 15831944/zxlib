//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "AppFileSys.h"
#include "StrTools.h"



class CAppPath 
{
private:
	CAppPath()
	{
		TCHAR szPath[MAX_PATH];
		::GetModuleFileName(NULL, szPath, MAX_PATH);
		for (int i = _tcslen(szPath); i >= 0; --i)
		{
			if (_T('\\')!=szPath[i] && _T('/')!=szPath[i])
				continue;

			szPath[i] = _T('\0');
			break;
		}

		m_strPath = szPath;
	}
	~CAppPath()
	{
	}

public:
	const tstring GetPath() const
	{ return m_strPath; }

	static CAppPath& GetSingleton()
	{
		static CAppPath instance;
		return instance;
	}

private:
	tstring m_strPath;
};

const tstring GetAppPath()
{
	return CAppPath::GetSingleton().GetPath();
}