#pragma once



// 1. Script 포인터만 알아도, 클래스명을 알아낼 수 있어야한다.

// 2. 구현한 모든 스크립트 리스트를 알아낼수 있어야 한다.

// 3. Script 의 클래스 네이밍만으로, Script 객체를 생성시킬 수 있어야 한다.


enum SCRIPT_TYPE
{
	BACKGROUND,
	CAMERAMOVE,
	MISSILE,
	PLAYER,
};

class CScript;

class CScriptMgr
{
public:
	static void GetScriptsName(vector<string>& _vecName);
	static string GetScriptName(CScript* _Script);
	static CScript* GetScript(const string& _scriptName);
};

