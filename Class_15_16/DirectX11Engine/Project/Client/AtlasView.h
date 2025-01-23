#pragma once
#include "TMESub.h"

class AtlasView :
    public TMESub
{

public:
    virtual void render_tick() override;

public:
    AtlasView();
    ~AtlasView();
};

