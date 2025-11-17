#pragma once
#include "Engine\\GameObject.h"

class Fbx; // ëOï˚êÈåæ

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
    void SetShooter(bool isPlayer) { isPlayerBullet_ = isPlayer; }
private:
    Fbx* pFbx_;
    int hModel_;
    float bulletSpeed_;
    bool isPlayerBullet_;
};

