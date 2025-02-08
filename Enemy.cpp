#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy() {
	posX_ = 100.0f;
	posY_ = 300.0f;
	velocityX_ = 4.0f;
	velocityY_ = 4.0f;
	radius_ = 15.0f;
	enemyIsHit = true;
}

Enemy::~Enemy() {

}


void Enemy::Move() {
	posX_ += velocityX_;
	posY_ += velocityY_;

	if (posX_ - radius_ <= 0.0f ||
		posX_ + radius_ >= 1280.0f) {
		velocityX_ *= -1;
	}
	if (posY_ - radius_ <= 0.0f ||
		posY_ + radius_ >= 720.0f) {
		velocityY_*= -1.0f;
	}
 }

void Enemy::Draw() {
	Novice::DrawEllipse(
		int(posX_), int(posY_),
		int(radius_), int(radius_),
		0.0f, RED, kFillModeSolid);
}

