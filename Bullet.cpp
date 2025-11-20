#include "Bullet.h"
#include "Engine\\Fbx.h"
#include "Engine\\Model.h"
#include "Engine\\SphereCollider.h"
#include <Windows.h>

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), pFbx_(nullptr), bulletSpeed_(1.0f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Egg.fbx");
	assert(hModel_ >= 0);

	SphereCollider* col = new SphereCollider(0.2f);
	AddCollider(col);
}

void Bullet::Update()
{
	transform_.scale_ = { 0.5f,0.5f,0.5f };
	transform_.position_.z += bulletSpeed_;
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
	//MessageBoxA(0, "’e‚ª“–‚½‚Á‚½", "Collider", MB_OK);
	//KillMe();
}
