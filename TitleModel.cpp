#include "TitleModel.h"
#include "Engine\\Fbx.h"
#include "Engine\\Model.h"

TitleModel::TitleModel(GameObject* parent)
	:GameObject(parent, "TitleModel"), pFbx_(nullptr)
{
}

TitleModel::~TitleModel()
{
}

void TitleModel::Initialize()
{
	pFbx_ = new Fbx;
	//pFbx_がnullptrじゃなかったらのチェックを入れたほうがいい
	pFbx_->Load("Gender.fbx");
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;
	transform_.scale_.z = 0.5f;

	hModel_ = Model::Load("Gender.fbx");
	assert(hModel_ >= 0);
}

void TitleModel::Update()
{
	transform_.rotate_.y += 0.5f;
	//if (transform_.rotate_.y > 360.0f)
	//{
	//	KillMe();
	//}

}

void TitleModel::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TitleModel::Release()
{
	if (pFbx_)
	{
		Model::Release();
	}
}
