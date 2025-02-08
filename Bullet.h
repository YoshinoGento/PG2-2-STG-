#pragma once
#include "Struct.h"



class Bullet {

public:
	Bullet();
	~Bullet();
	void Update();
	void Draw();

	//==================
	// Get
	// =================
	//Pos
	float GetPosX() { return posX_; }
	float GetPosY() { return posY_; }

	//Velocity
	float GetVelocityX() { return velocityX_; }
	float GetVelocityY() { return velocityY_; }

	//radius
	float GetRadius() { return radius_; }

	//isShot
	bool GetIsShot() { return isShot_; }

	

	//========================
	//Set
	//========================
	//Pos
	void SetPosX(float posX ) { posX_ = posX; }
	void SetPosY(float posY ) { posY_ = posY; }

	//Velocity
	void SetVelocityX(float velocityX) { velocityX_ = velocityX;}
	void SetVelocityY(float velocityX) { velocityX_ = velocityX;}

	//radius
	void SetRadius(float radius) { radius_ = radius; }

	//IsShot
	void SetIsShot(bool isShot) { isShot_ = isShot; }

private:
	float posX_;
	float posY_;
	float velocityX_;
	float velocityY_;
	float radius_;
	bool isShot_;
};

