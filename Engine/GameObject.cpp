#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::DrawSub()
{
	//自分を描画
	this->Draw();
	//子オブジェクトを描画 childList_の各要素に対してDrawを呼ぶ
	//for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	//{
	//	 (*itr)->DrawSub();
	//}
		for (auto child : this->childList_)
		{
			child->DrawSub();
	}
}

void GameObject::UpdateSub()
{
	this->Update();
	for (auto child : this->childList_)
	{
		child->UpdateSub();
	}
}

void GameObject::ReleaseSub()
{
	this->Release();
	for (auto child : this->childList_)
	{
		child->ReleaseSub();
	}
}
