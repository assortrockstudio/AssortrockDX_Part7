#pragma once
#include "TMESub.h"

class TileView :
    public TMESub
{
private:
    float m_DefaultSize;
    float m_CaptureScale;

    Vec2  m_ImageRectMin;


public:
    virtual void render_tick() override;
    virtual void Deactivate() override;

private:
    void MouseCheck();

public:
    TileView();
    ~TileView();
};

