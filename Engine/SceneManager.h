#pragma once
#include "GameObject.h"

// �V�[��ID�̗񋓌^
enum SCENE_ID
{
	SCENE_ID_TEST,
	SCENE_ID_PLAY,
	SCENE_ID_MAX
};

class SceneManager :
	public GameObject
{
public:
	SceneManager(GameObject* parent);
	~SceneManager();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void ChangeScene(SCENE_ID nextScene);
private:
	SCENE_ID currentSceneID_;
	SCENE_ID nextSceneID_;
};