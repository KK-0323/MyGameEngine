#pragma once
#include "Engine\\GameObject.h"

class Fbx; // ‘O•ûéŒ¾

class Bullet :
    public GameObject
{
public:
    Bullet(GameObject* parent);
    ~Bullet();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void OnCollision(GameObject* pTarget) override;
private:
    Fbx* pFbx_;
    int hModel_;
    float bulletSpeed_;
};

