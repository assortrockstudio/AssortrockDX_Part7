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
		MessageBox(nullptr, L"파일 저장 실패", L"레벨 저장 실패", MB_OK);
		return;
	}

	// 레벨의 이름을 저장
	SaveWString(_Level->GetName(), pFile);

	// 레벨이 소유한 모든 레이어 정보를 저장
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		// 레이어의 이름을 저장
		CLayer* pLayer = _Level->GetLayer(i);
		SaveWString(pLayer->GetName(), pFile);

		// 레이어가 보유한 오브젝트들을 저장(부모 오브젝트들 기준)
		const vector<CGameObject*>& vecParents = pLayer->GetParentObjects();

		// ParentObject 개수 저장
		size_t ObjCount = vecParents.size();
		fwrite(&ObjCount, sizeof(size_t), 1, pFile);

		// Layer 에 소속된 각각의 GameObject 정보를 저장
		for (size_t i = 0; i < ObjCount; ++i)
		{
			SaveGameObject(vecParents[i], pFile);
		}
	}

	fclose(pFile);
}

void CLevelSaveLoad::SaveGameObject(CGameObject* _Object, FILE* _File)
{
	// 이름
	SaveWString(_Object->GetName(), _File);
		
	// 컴포넌트
	for (UINT i = 0; i < (UINT)COMPONENT_TYPE::END; ++i)
	{
		CComponent* pComopnent = _Object->GetComponent((COMPONENT_TYPE)i);
		if (nullptr == pComopnent)
			continue;

		pComopnent->SaveToLevelFile(_File);
	}
	

	// 스크립트

	// 자식 오브젝트

}

CLevel* CLevelSaveLoad::LoadLevel(const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"rb");

	if (nullptr == pFile)
	{
		MessageBox(nullptr, L"파일 불러오기 실패", L"레벨 로드 실패", MB_OK);
		return nullptr;
	}

	CLevel* pLevel = new CLevel;

	// 레벨의 이름을 로드
	wstring strLevelName;
	LoadWString(strLevelName, pFile);
	pLevel->SetName(strLevelName);

	// 레벨이 소유한 모든 레이어 정보를 로딩
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		// 레이어의 이름을 로드
		CLayer* pLayer = pLevel->GetLayer(i);
		wstring strLayerName;
		LoadWString(strLayerName, pFile);		
		pLayer->SetName(strLayerName);

		// 레이어가 보유한 오브젝트들을 로드(부모 오브젝트들 기준)
		// ParentObject 개수 로드
		size_t ObjCount = 0;
		fread(&ObjCount, sizeof(size_t), 1, pFile);

		// 저장된 오브젝트 개수만큼 반복문 돌면서, 오브젝트를 로딩해서 레이어에 다시 넣어준다.
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

	// 이름
	wstring Name;
	LoadWString(Name, _File);
	pObject->SetName(Name);
		
	// 컴포넌트
	COMPONENT_TYPE type = COMPONENT_TYPE::END;

	while (true)
	{
		fread(&type, sizeof(UINT), 1, _File);


	}

	// 스크립트

	// 자식 오브젝트

}
