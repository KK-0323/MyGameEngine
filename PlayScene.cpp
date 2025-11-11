#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	//Playerのインスタンスを生成して、子オブジェクトに追加する
	//Player* pPlayer = new Player(this);
	//pPlayer->Initialize();
	//childList_.push_back(pPlayer);

	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	if (Input::IsKeyDown(DIK_C))
	{
		GameObject* sceneManagerObj = this->GetRootJob()->FindObject("SceneManager");
		if (sceneManagerObj != nullptr)
		{
			SceneManager* sceneManager = dynamic_cast<SceneManager*>(sceneManagerObj);
			if (sceneManager != nullptr)
			{
				sceneManager->ChangeScene(SCENE_ID_CLEAR);
			}
		}
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
