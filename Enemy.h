#pragma once
#include "Struct.h"
class Enemy {
public:
	Enemy();
	~Enemy();
	void Move();
	void Draw();
	
	//==============
	//Get
	//==============
	//Pos
	float GetPosX() { return posX_; }
	float GetPosY() { return posY_; }
	//Velocity
	float GetVelocityX() { return velocityX_; }
	float GetVelocityY() { return velocityY_; }
	//radius
	float GetRadius() { return radius_; }
	//IsShot
	bool GetIsShot() { return enemyIsHit; }
	
	//======================
	//Set
	//======================
	//Pos
	void SetPosX(float posX) { posX_ = posX; }
	void SetPosY(float posY) { posY_ = posY; }
	//Velocity
	void SetVelocityX(float velocityX) { velocityX_ = velocityX; }
	void SetVelocityY(float velocityY) { velocityY_ = velocityY; }
	//radius
	void SetRadius(float radius) { radius_ = radius; }
	//isShotz
	void SetIsShot(bool isShot) { enemyIsHit = isShot; }
private:
	float posX_;
	float posY_;
	float velocityX_;
	float velocityY_;
	float radius_;
	bool enemyIsHit;
	
};

