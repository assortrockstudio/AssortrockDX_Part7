#pragma once
#include "CRenderComponent.h"


struct tTileInfo
{
    UINT ImgIdx;
    Vec3 vPadding;
};

class CStructuredBuffer;

class CTileMap :
    public CRenderComponent
{
private:
    UINT                m_Row;          // Tile Row Count
    UINT                m_Col;          // Tile Colum Count
    Vec2                m_TileEachSize; // 각 타일 1개의 크기

    Ptr<CTexture>       m_Atlas;
    UINT                m_AtlasMaxRow;
    UINT                m_AtlasMaxCol;
    Vec2                m_AtlasTileEachSize;
    Vec2                m_AtlasResolution;

    vector<tTileInfo>   m_vecTileInfo;
    CStructuredBuffer*  m_TileBuffer;

public:
    void SetRowCol(UINT _Row, UINT _Col);
    void SetAltasTexture(Ptr<CTexture> _Tex);
    void SetAltasTileSize(Vec2 _TileSize);
    void SetTileEachSize(Vec2 _vSize);

    UINT GetRow() { return m_Row; }
    UINT GetColumn() { return m_Col; }
    Vec2 GetTileSize() { return m_TileEachSize; }

    Ptr<CTexture> GetAltas() { return m_Atlas; }
    UINT GetAltasMaxRow() { return m_AtlasMaxRow; }
    UINT GetAltasMaxColumn() { return m_AtlasMaxCol; }
    Vec2 GetAltasTileSize() { return m_AtlasTileEachSize; }

public:
    virtual void begin() override;
    virtual void finaltick() override;
    virtual void render() override;

public:
    virtual void SaveToLevelFile(FILE* _File) override;
    virtual void LoadFromLevelFile(FILE* _File) override;
    CLONE(CTileMap);
    CTileMap();
    CTileMap(const CTileMap& _Other);
    ~CTileMap();
};

