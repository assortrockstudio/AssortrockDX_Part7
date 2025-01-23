#pragma once



// 1. Script �����͸� �˾Ƶ�, Ŭ�������� �˾Ƴ� �� �־���Ѵ�.

// 2. ������ ��� ��ũ��Ʈ ����Ʈ�� �˾Ƴ��� �־�� �Ѵ�.

// 3. Script �� Ŭ���� ���ָ̹�����, Script ��ü�� ������ų �� �־�� �Ѵ�.


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

