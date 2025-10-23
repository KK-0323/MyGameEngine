#include "TestScene.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
}

void TestScene::Update()
{
	// �X�y�[�X�L�[����������
	// SceneManager::ChangeScene(SCENE_ID_PLAY);���Ăяo��
	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* sceneManagerObj = this->GetRootJob()->FindObject("SceneManager");
		if (sceneManagerObj != nullptr)
		{
			SceneManager* sceneManager = dynamic_cast<SceneManager*>(sceneManagerObj);
			if (sceneManager != nullptr)
			{
				sceneManager->ChangeScene(SCENE_ID_PLAY);
			}
		}
	}
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
