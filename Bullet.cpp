#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet() {
	posX_  = 100.0f;
	posY_  = 100.0f;
	velocityX_ = 0.0f;
	velocityY_ = 25.0f;
	radius_ = 10.0f;
	isShot_ = false;
}

Bullet::~Bullet() {
}

void Bullet::Update() {
	if (isShot_ == true) {
		posY_ -= velocityY_;
	}
	if (posY_ <=0.0f) {
		isShot_ = false;
	}
}

void Bullet::Draw() {
	if (isShot_ == true) {

		Novice::DrawEllipse(
			int(posX_), int(posY_),
			int(radius_), int(radius_),
			0.0f, RED, kFillModeSolid);
	}
}
