#include "pch.h"
#include "CLevelSaveLoad.h"

#include <Engine/CLevelMgr.h>
#include <Engine/CLevel.h>
#include <Engine/CLayer.h>
#include <Engine/CGameObject.h>
#include <Engine/components.h>
#include <Engine/CCollisionMgr.h>

void CLevelSaveLoad::SaveLevel(CLevel* _Level, const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"wb");

	if (nullptr == pFile)
	{
		MessageBox(nullptr, L"���� ���� ����", L"���� ���� ����", MB_OK);
		return;
	}

	// ������ �̸��� ����
	SaveWString(_Level->GetName(), pFile);

	// ������ ������ ��� ���̾� ������ ����
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		// ���̾��� �̸��� ����
		CLayer* pLayer = _Level->GetLayer(i);
		SaveWString(pLayer->GetName(), pFile);

		// ���̾ ������ ������Ʈ���� ����(�θ� ������Ʈ�� ����)
		const vector<CGameObject*>& vecParents = pLayer->GetParentObjects();

		// ParentObject ���� ����
		size_t ObjCount = vecParents.size();
		fwrite(&ObjCount, sizeof(size_t), 1, pFile);

		// Layer �� �Ҽӵ� ������ GameObject ������ ����
		for (size_t i = 0; i < ObjCount; ++i)
		{
			SaveGameObject(vecParents[i], pFile);
		}
	}

	fclose(pFile);
}

void CLevelSaveLoad::SaveGameObject(CGameObject* _Object, FILE* _File)
{
	// �̸�
	SaveWString(_Object->GetName(), _File);
		
	// ������Ʈ
	for (UINT i = 0; i < (UINT)COMPONENT_TYPE::END; ++i)
	{
		CComponent* pComopnent = _Object->GetComponent((COMPONENT_TYPE)i);
		if (nullptr == pComopnent)
			continue;

		pComopnent->SaveToLevelFile(_File);
	}
	

	// ��ũ��Ʈ

	// �ڽ� ������Ʈ

}

CLevel* CLevelSaveLoad::LoadLevel(const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"rb");

	if (nullptr == pFile)
	{
		MessageBox(nullptr, L"���� �ҷ����� ����", L"���� �ε� ����", MB_OK);
		return nullptr;
	}

	CLevel* pLevel = new CLevel;

	// ������ �̸��� �ε�
	wstring strLevelName;
	LoadWString(strLevelName, pFile);
	pLevel->SetName(strLevelName);

	// ������ ������ ��� ���̾� ������ �ε�
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		// ���̾��� �̸��� �ε�
		CLayer* pLayer = pLevel->GetLayer(i);
		wstring strLayerName;
		LoadWString(strLayerName, pFile);		
		pLayer->SetName(strLayerName);

		// ���̾ ������ ������Ʈ���� �ε�(�θ� ������Ʈ�� ����)
		// ParentObject ���� �ε�
		size_t ObjCount = 0;
		fread(&ObjCount, sizeof(size_t), 1, pFile);

		// ����� ������Ʈ ������ŭ �ݺ��� ���鼭, ������Ʈ�� �ε��ؼ� ���̾ �ٽ� �־��ش�.
		for (size_t i = 0; i < ObjCount; ++i)
		{		
			CGameObject* pParentObject = LoadGameObject(pFile);
			pLayer->AddObject(pParentObject);
		}
	}

	fclose(pFile);

	return pLevel;
}

CGameObject* CLevelSaveLoad::LoadGameObject(FILE* _File)
{
	CGameObject* pObject = new CGameObject;

	// �̸�
	wstring Name;
	LoadWString(Name, _File);
	pObject->SetName(Name);
		
	// ������Ʈ
	COMPONENT_TYPE type = COMPONENT_TYPE::END;

	while (true)
	{
		fread(&type, sizeof(UINT), 1, _File);


	}

	// ��ũ��Ʈ

	// �ڽ� ������Ʈ

}
