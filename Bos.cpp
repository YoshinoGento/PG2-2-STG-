#include "Bos.h"
#include "Novice.h"

Bos::Bos() {
	posX_ = 640.0f;
	posY_ = 60.0f;
	radius_ = 50.0f;
	bosIsHit = false;
	lifeCount_ = 10;
	enemy_ = new Enemy;
}

Bos::~Bos() {
}

void Bos::Update() {
	if (lifeCount_ <= 0) {
		bosIsHit = false;
	}
	if (bosIsHit == false) {
		bosIsHit = true;
		enemy_->SetPosX(posX_);
		enemy_->SetPosX(posY_);
	}
}

void Bos::Draw() {
	if (bosIsHit == true) {
		Novice::DrawEllipse(
			int(posX_), int(posY_),
			int(radius_), int(radius_),
			0.0f, BLUE, kFillModeSolid);
	}
}
