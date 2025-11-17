#include "Bullet.h"
#include "Engine\\Fbx.h"
#include "Engine\\Model.h"
#include "Engine\\SphereCollider.h"
#include <Windows.h>

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), pFbx_(nullptr), bulletSpeed_(1.0f), isPlayerBullet_(true)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Egg.fbx");
	assert(hModel_ >= 0);

	transform_.position_.z = -40.0f;
	transform_.scale_ = { 0.5f,0.5f,0.5f };

	//SphereCollider* col = new SphereCollider(0.3f);
	//AddCollider(col);
}

void Bullet::Update()
{
	if(isPlayerBullet_ = true)
	{ 
		transform_.position_.z -= bulletSpeed_;
	}
	else if(isPlayerBullet_ = false)
	{
		transform_.position_.z += bulletSpeed_;
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
	if (pFbx_)
	{
		Model::Release();
	}
}

void Bullet::OnCollision(GameObject* pTarget)
{
	MessageBoxA(0, "’e‚ª“–‚½‚Á‚½", "Collider", MB_OK);
	//KillMe();
}
