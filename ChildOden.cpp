#include "ChildOden.h"
#include "Engine\\Fbx.h"
#include "Engine\\Model.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent, "ChildOden"), hModel_(-1)
{
	pFbx_ = new Fbx;
	//pFbx_��nullptr����Ȃ�������̃`�F�b�N����ꂽ�ق�������
	pFbx_->Load("oden.fbx");
	transform_.scale_.x = 0.2f;
	transform_.scale_.y = 0.2f;
	transform_.scale_.z = 0.2f;
	transform_.position_.x = 2.0f;
	transform_.position_.y = 1.0f;
	hModel_ = Model::Load("oden.fbx");
	assert(hModel_ >= 0);
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
}

void ChildOden::Update()
{
	transform_.rotate_.y += 0.5f;
}

void ChildOden::Draw()
{
	//if (pFbx_)
	//{
	//	pFbx_->Draw(transform_);
	//}
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void ChildOden::Release()
{
	if (pFbx_)
	{
		//pFbx_->Release();
		//delete pFbx_;
		//pFbx_ = nullptr;
		Model::Release();
	}
}
