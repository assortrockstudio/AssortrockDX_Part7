#include "pch.h"
#include "CScriptMgr.h"

#include "CBackgroundScript.h"
#include "CPlayerScript.h"
#include "CMissileScript.h"
#include "CCameraMoveScript.h"

void CScriptMgr::GetScriptsName(vector<string>& _vecName)
{
	_vecName.push_back("CBackgroundScript");
	_vecName.push_back("CCameraMoveScript");
	_vecName.push_back("CMissileScript");
	_vecName.push_back("CPlayerScript");
}

string CScriptMgr::GetScriptName(CScript* _Script)
{
	SCRIPT_TYPE type = (SCRIPT_TYPE)_Script->GetScriptType();

	switch (type)
	{
	case BACKGROUND:
		return "CBackgroundScript";		
	case CAMERAMOVE:
		return "CCameraMoveScript";	
	case MISSILE:
		return "CMissileScript";		
	case PLAYER:
		return "CPlayerScript";		
	}

	return string();
}

CScript* CScriptMgr::GetScript(const string& _scriptName)
{
	if (_scriptName == "CBackgroundScript")
		return new CBackgroundScript;
	if (_scriptName == "CCameraMoveScript")
		return new CCameraMoveScript;
	if (_scriptName == "CMissileScript")
		return new CMissileScript;
	if (_scriptName == "CPlayerScript")
		return new CPlayerScript;

	return nullptr;
}
