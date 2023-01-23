#pragma once
class SceneManager final
{
private:

	SceneManager();

	~SceneManager();

	int scene;
public:

	//コピーコンストラクタを無効
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無効
	SceneManager& operator = (const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	//シーン切り替え
	void ChangeScene(int sceneNo);

	//ゲッター
	int GetScene() { return scene; }
};

