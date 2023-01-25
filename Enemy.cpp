#include "Enemy.h"
#include "DxLib.h"

void Enemy::Initialize() {

}

void Enemy::Update() {
	
}

void Enemy::Draw(int eState) {
	(this->*enemyState[eState])();
}

void Enemy::Proximity() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "���݂̏�� : �ߐ�");
}

void Enemy::Shooting() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "���݂̏�� : �ˌ�");
}

void Enemy::Secession() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "���݂̏�� : ���E");
}

void (Enemy::* Enemy::enemyState[])() = {
	&Enemy::Proximity,
	&Enemy::Shooting,
	&Enemy::Secession,
};