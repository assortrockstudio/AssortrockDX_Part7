#include "pch.h"
#include "CLevel.h"

#include "CLayer.h"
#include "CGameObject.h"
#include "CRenderMgr.h"

CLevel::CLevel()
	: m_arrLayer{}
	, m_State(LEVEL_STATE::STOP)
{
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		m_arrLayer[i] = new CLayer;
		m_arrLayer[i]->m_LayerIdx = i;
	}
}

CLevel::~CLevel()
{
	Safe_Del_Array(m_arrLayer);
}



void CLevel::begin()
{
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		m_arrLayer[i]->begin();
	}
}

void CLevel::tick()
{
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		m_arrLayer[i]->tick();
	}
}

void CLevel::finaltick()
{
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		m_arrLayer[i]->finaltick();
	}
}

void CLevel::RegisterClear()
{
	// ���� �����ӿ� ��ϵ� ������Ʈ���� ����
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		m_arrLayer[i]->Clear();
	}

}

void CLevel::AddObject(UINT _LayerIdx, CGameObject* _Object, bool _bChildMove)
{
	m_arrLayer[_LayerIdx]->AddObject(_Object, _bChildMove);
}

void CLevel::ChangeState(LEVEL_STATE _NextState)
{
	if (LEVEL_STATE::STOP == _NextState || LEVEL_STATE::PAUSE == _NextState)
		CRenderMgr::GetInst()->ChangeRenderMode(RENDER_MODE::EDITOR);

	// ������ ���·��� ��ȯ�� �߻��� ���, return
	if (m_State == _NextState)
		return;

	// �������¿��� �Ͻ������� �Ѿ�� ���
	assert(!(LEVEL_STATE::STOP == m_State && LEVEL_STATE::PAUSE == _NextState));

	if (LEVEL_STATE::STOP == m_State && LEVEL_STATE::PLAY == _NextState)
	{
		begin();
	}

	m_State = _NextState;
}


CGameObject* CLevel::FindObjectByName(const wstring& _Name)
{
	for (UINT i = 0; i < MAX_LAYER; ++i)
	{
		const vector<CGameObject*>& vecObjects = m_arrLayer[i]->GetObjects();
		for (size_t j = 0; j < vecObjects.size(); ++j)
		{
			if (_Name == vecObjects[j]->GetName())
			{
				return vecObjects[j];
			}
		}
	}	

	return nullptr;
}