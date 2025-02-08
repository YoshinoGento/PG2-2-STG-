#include "Player.h"
#include "Enemy.h"
#include "Novice.h"
#include "Struct.h"
#include "Bullet.h"
Player::Player() {
	pos_.x = 640.0f;
	pos_.y = 310.0f;
	speed_ = 17.0f;
	radius_ = 16.0f;
	playerLife_ = 3;
	isAlive_ = true;
	bullet_ = new Bullet();

}

Player::~Player() {
}
void Player::Move(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {

		if (bullet_->GetIsShot() == false) {
			bullet_->SetPosX(pos_.x);
			bullet_->SetPosY(pos_.y);
			bullet_->SetIsShot(true);
		}

	}

	bullet_->Update();

}
void Player::Draw() {

	bullet_->Draw();

	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_),
		int(radius_), 0.0f, BLACK,
		kFillModeSolid);
}


void Player::HitTest() {
}
