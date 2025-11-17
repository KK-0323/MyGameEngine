#pragma once
#include "Engine\\GameObject.h"
#include "Engine\\Fbx.h"

class SceneManager; // ‘O•ûéŒ¾

class Enemy :
    public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
private:
	Fbx* pFbx_;
	float shootTimer_;
	const float SHOOT_INTERVAL = 120.0f;
};

