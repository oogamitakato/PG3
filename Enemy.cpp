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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "現在の状態 : 近接");
}

void Enemy::Shooting() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "現在の状態 : 射撃");
}

void Enemy::Secession() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "現在の状態 : 離脱");
}

void (Enemy::* Enemy::enemyState[])() = {
	&Enemy::Proximity,
	&Enemy::Shooting,
	&Enemy::Secession,
};