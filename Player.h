#pragma once
#include "Struct.h"
#include "Bullet.h"


class Player {
public:
	//コンストラクタ
	Player();
	~Player();

public:
	//メンバー関数
	void Draw();
	void Move(char* keys, char* preKeys);
	//弾とplayerの当たり判定
	void HitTest();
	
	//==============
	//Get
	//==============
	//Pos
	Vector2 GetPos() { return pos_; }

	//Velocity
	float GetSpeed() { return speed_; }
	//radius
	float GetRadius() { return radius_; }
	//IsShot
	bool GetIsAlive() { return isAlive_; }

	int GetPlayerLife() { return playerLife_; }

	//Bullet
	Bullet* GetBullet() { return bullet_; }
	//======================
	//Set
	//======================
	//Pos
	void SetPos(Vector2 pos) { pos_ = pos; }
	
	//Velocity
	void SetSpeed(float speed) { speed_ = speed; }
	
	//radius
	void SetRadius(float radius) { radius_ = radius; }
	//isShotz
	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }

	//playerLife
	void SetPlayerLife_(int playerLife) { playerLife_ = playerLife; }

private:
	//メンバー変数
	Vector2 pos_;
	float speed_;
	float radius_;
	bool isAlive_;
	int playerLife_;
	Bullet *bullet_;
};

