#pragma once
#include "Engine\\GameObject.h"

class Fbx; // �O���錾

class TitleModel :
    public GameObject
{
public:
	TitleModel(GameObject* parent);
	~TitleModel();
	// �������z�֐��̃I�[�o�[���C�h
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Fbx* pFbx_;
	int hModel_;
};

