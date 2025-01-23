#pragma once
#include "TMESub.h"
class TileMapDetail :
    public TMESub
{


public:
    virtual void render_tick() override;

public:
    TileMapDetail();
    ~TileMapDetail();
};

