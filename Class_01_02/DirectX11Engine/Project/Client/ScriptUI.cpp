#include "pch.h"
#include "ScriptUI.h"

ScriptUI::ScriptUI()
	: ComponentUI("ScriptUI", "##ScriptUI", COMPONENT_TYPE::SCRIPT)
{
}

ScriptUI::~ScriptUI()
{
}

void ScriptUI::render_tick()
{
	m_TargetScript;

	render_title();
}

// 1. Script �����͸� �˾Ƶ�, Ŭ�������� �˾Ƴ� �� �־���Ѵ�.

// 2. ������ ��� ��ũ��Ʈ ����Ʈ�� �˾Ƴ��� �־�� �Ѵ�.

// 3. Script �� Ŭ���� ���ָ̹�����, Script ��ü�� ������ų �� �־�� �Ѵ�.