#include "stdafx.h"
#include "Config.h"
#include "path.h"

static CConfig cfg;

//////////////////////////////////////////////////////////////////////////
CConfig::CConfig()
{
    RegisterEvent(evCfgSetBOOLVal, this, &CConfig::SetBOOLValue);
    RegisterEvent(evCfgGetBOOLVal, this, &CConfig::GetBOOLValue);
    RegisterEvent(evCfgSetINTVal, this, &CConfig::SetINTValue);
    RegisterEvent(evCfgGetINTVal, this, &CConfig::GetINTValue);
    RegisterEvent(evCfgSetSTRVal, this, &CConfig::SetSTRTValue);
    RegisterEvent(evCfgGetSTRVal, this, &CConfig::GetSTRValue);

    LSTATUS status = key.Create(HKEY_CURRENT_USER, _T("SOFTWARE\\WTL Builder"));
    _ASSERT_EXPR(status == ERROR_SUCCESS, "Could not open HKCU\\SOFTWARE\\WTL Builder");
}


CConfig::~CConfig()
{
    key.Close();
}

void CConfig::SetBOOLValue(LPCTSTR section, LPCTSTR key, BOOL val)
{
    CRegKey subKey;
    LSTATUS status = subKey.Create(this->key, section);
    _ASSERT_EXPR(status == ERROR_SUCCESS, "Could not open section subkey");

    subKey.SetDWORDValue(key, val ? 1 : 0);
    subKey.Close();
}

void CConfig::GetBOOLValue(LPCTSTR section, LPCTSTR key, BOOL *val)
{
    if (val == NULL) return;

    CRegKey subKey;
    LSTATUS status = subKey.Create(this->key, section);
    _ASSERT_EXPR(status == ERROR_SUCCESS, "Could not open section subkey");

    DWORD rawValue;
    status = subKey.QueryDWORDValue(key, rawValue);
    if (status == ERROR_SUCCESS) *val = (rawValue != 0);
    subKey.Close();
}

void CConfig::SetINTValue(LPCTSTR section, LPCTSTR key, int val)
{
    CRegKey subKey;
    LSTATUS status = subKey.Create(this->key, section);
    _ASSERT_EXPR(status == ERROR_SUCCESS, "Could not open section subkey");

    subKey.SetDWORDValue(key, val);
    subKey.Close();
}

void CConfig::GetINTValue(LPCTSTR section, LPCTSTR key, int *val)
{
    if (val == NULL) return;

    CRegKey subKey;
    LSTATUS status = subKey.Create(this->key, section);
    _ASSERT_EXPR(status == ERROR_SUCCESS, "Could not open section subkey");

    DWORD rawValue;
    status = subKey.QueryDWORDValue(key, rawValue);
    if (status == ERROR_SUCCESS) *val = (int)rawValue;
    subKey.Close();
}

void CConfig::SetSTRTValue(LPCTSTR section, LPCTSTR key, LPCTSTR val)
{
    CRegKey subKey;
    LSTATUS status = subKey.Create(this->key, section);
    _ASSERT_EXPR(status == ERROR_SUCCESS, "Could not open section subkey");

    subKey.SetStringValue(key, val);
    subKey.Close();
}

void CConfig::GetSTRValue(LPCTSTR section, LPCTSTR key, LPTSTR val, int sz)
{
    if (val == NULL) return;

    CRegKey subKey;
    LSTATUS status = subKey.Create(this->key, section);
    _ASSERT_EXPR(status == ERROR_SUCCESS, "Could not open section subkey");

    DWORD privateSize = sz;
    subKey.QueryStringValue(key, val, &privateSize);
    subKey.Close();
}
