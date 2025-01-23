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
	GetTileMap();


}
