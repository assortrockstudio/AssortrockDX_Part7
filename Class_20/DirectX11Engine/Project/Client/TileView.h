#pragma once
#include "TMESub.h"

class TileView :
    public TMESub
{
private:


public:
    virtual void render_tick() override;
    virtual void Deactivate() override;

public:
    TileView();
    ~TileView();
};

