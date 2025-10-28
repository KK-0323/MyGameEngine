#pragma once
#include "Engine\\GameObject.h"

class Fbx; // 前方宣言

class TitleModel :
    public GameObject
{
public:
	TitleModel(GameObject* parent);
	~TitleModel();
	// 純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Fbx* pFbx_;
	int hModel_;
};

