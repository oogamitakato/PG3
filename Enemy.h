#pragma once
class Enemy
{
public:
	static int isAlive;

	void Initialize();

	void Update();

	void Draw(int eState);

	void Proximity();
	void Shooting();
	void Secession();

private:
	static void (Enemy::* enemyState[])();
};