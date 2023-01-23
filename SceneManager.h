#pragma once
class SceneManager final
{
private:

	SceneManager();

	~SceneManager();

	int scene;
public:

	//�R�s�[�R���X�g���N�^�𖳌�
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳌�
	SceneManager& operator = (const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	//�V�[���؂�ւ�
	void ChangeScene(int sceneNo);

	//�Q�b�^�[
	int GetScene() { return scene; }
};

