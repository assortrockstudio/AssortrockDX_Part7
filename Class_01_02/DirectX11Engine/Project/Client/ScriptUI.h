#pragma once
#include "ComponentUI.h"

class CScript;

class ScriptUI :
    public ComponentUI
{
private:
    CScript* m_TargetScript;


public:
    void SetScript(CScript* _Script) { m_TargetScript = _Script; }

public:
    virtual void render_tick() override;

public:
    ScriptUI();
    ~ScriptUI();
};

