#include "TestScene.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"
#include "TitleModel.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
	// TitleModelのインスタンスを生成して、子オブジェクトに追加する
	Instantiate<TitleModel>(this);
}

void TestScene::Update()
{
	// スペースキーを押したらプレイシーンを呼び出す
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
