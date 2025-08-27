#pragma once
#include "Quad.h"
#include "Transform.h"

class Dice :
    public Quad
{
public:
    Dice();
    ~Dice();
    HRESULT Initialize() override;
    void Draw(Transform& transform) override;
    void Release();
};

