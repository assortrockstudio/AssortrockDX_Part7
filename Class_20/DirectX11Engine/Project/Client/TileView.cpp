#include "pch.h"
#include "TileView.h"

TileView::TileView()
	: TMESub("TileView", "##TileView")
{
}

TileView::~TileView()
{
}

void TileView::render_tick()
{
	CTileMap* pTileMap = GetTileMap();

	
}

void TileView::Deactivate()
{
	CTileMap* pTileMap = GetTileMap();
	if(nullptr != pTileMap)
		pTileMap->SetCapture(false);
}
