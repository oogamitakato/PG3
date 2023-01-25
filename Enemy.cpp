#include "Enemy.h"
#include "DxLib.h"

void Enemy::Initialize() {

}

void Enemy::Update() {

}

void Enemy::Draw(int x, int y) {

	if (isAlive == 1) {
		DrawCircle(x, y, 10, GetColor(255, 255, 255), true);
	}

}