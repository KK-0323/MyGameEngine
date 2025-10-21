#pragma once
#include "Engine\\GameObject.h"

class Fbx; // 前方宣言
class ChildOden;

class Player :
    public GameObject
{
public:
    Player(GameObject* parent);
    ~Player();
    // 純粋仮想関数のオーバーライド
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
private:
    Fbx* pFbx_;
    ChildOden* pRChildOden_;
    ChildOden* pLChildOden_;
	int hModel_;
};

