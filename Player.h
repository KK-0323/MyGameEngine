#pragma once
#include "Engine\\GameObject.h"

class Fbx; // 前方宣言

class Player :
    public GameObject
{
    Fbx* pFbx_;
public:
    Player(GameObject* parent);
    ~Player();
    // 純粋仮想関数のオーバーライド
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

