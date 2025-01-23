#include "pch.h"
#include "TileMapDetail.h"

TileMapDetail::TileMapDetail()
	: TMESub("Detail", "##TileMapDetail")
{
}

TileMapDetail::~TileMapDetail()
{
}

void TileMapDetail::render_tick()
{
	CTileMap* pTileMap = GetTileMap();

	if (nullptr == pTileMap)
		return;


	int row_col[2] = { pTileMap->GetRow(), pTileMap->GetColumn()};
	ImGui::InputInt2("##TileMapRow_Col", row_col);

	
	//Vec2                m_TileEachSize; // �� Ÿ�� 1���� ũ��
	//Ptr<CTexture>       m_Atlas;
	//Vec2                m_AtlasTileEachSize;

	//// Read-Olny
	//UINT                m_AtlasMaxRow;
	//UINT                m_AtlasMaxCol;
	//Vec2                m_AtlasResolution;
}