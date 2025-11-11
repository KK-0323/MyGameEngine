#include "ClearScene.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene")
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* sceneManagerObj = this->GetRootJob()->FindObject("SceneManager");
		if (sceneManagerObj != nullptr)
		{
			SceneManager* sceneManager = dynamic_cast<SceneManager*>(sceneManagerObj);
			if (sceneManager != nullptr)
			{
				sceneManager->ChangeScene(SCENE_ID_TEST);
			}
		}
	}
}

void ClearScene::Draw()
{
}

void ClearScene::Release()
{
}
