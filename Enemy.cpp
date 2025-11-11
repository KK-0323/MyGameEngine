#include "Enemy.h"
#include "Engine\\SphereCollider.h"
#include "Engine\\SceneManager.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), pFbx_(nullptr)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	pFbx_ = new Fbx;
	pFbx_->Load("oden.fbx");
	transform_.position_ = { 0.0f, 0.0f, 50.0f };

	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	pFbx_->Draw(transform_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	//MessageBoxA(0, "Enemy‚ª‚Ô‚Â‚©‚Á‚½", "Collider", MB_OK);
	if (pTarget->GetName() == "Bullet")
	{
		KillMe();	// “G
		pTarget->KillMe();	// ’e

		GameObject* sceneObj = this->GetRootJob()->FindObject("SceneManager");
		if (sceneObj != nullptr)
		{
			SceneManager* sceneManager = dynamic_cast<SceneManager*>(sceneObj);
			if (sceneManager != nullptr)
			{
				sceneManager->ChangeScene(SCENE_ID_CLEAR);
			}
		}
	}
}
