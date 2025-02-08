#pragma once
#include "Enemy.h"
class Bos {
public:
	Bos();
	~Bos();
	void Update();
	void Draw();
	Enemy* enemy_;

	//==============
	//Get
	//==============
	//Pos
	float GetPosX() { return posX_; }
	float GetPosY() { return posY_; }
	
	//radius
	float GetRadius() { return radius_; }

	//lifeCount
	int GetLifeCount() { return lifeCount_; }

	//IsShot
	bool GetIsShot() { return bosIsHit; }
	//==========================


	//======================
	//Set
	//======================
	//Pos
	void SetPosX(float posX) { posX_ = posX; }
	void SetPosY(float posY) { posY_ = posY; }
	
	//radius
	void SetRadius(float radius) { radius_ = radius; }

	//lifeCount
	void SetLifeCount(int damage) { lifeCount_ = damage; }

	//isShotz
	void SetIsShot(bool isShot) { bosIsHit = isShot; }
private:
	float posX_;
	float posY_;
	float radius_;
	int lifeCount_;
	bool bosIsHit;

};


