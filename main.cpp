#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Bos.h"
#include <math.h>



const char kWindowTitle[] = "LC1C_26_ヨシノ_ゲント";

//int Enemy::enemyIsHit = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
    Bos* bos_ = new Bos();
	Enemy* enemyA = new Enemy();
	Enemy* enemyB = new Enemy();
	Bullet* bullet = new Bullet();
	Player* player = new Player();
	
	Scene scene = TITLE;

	float distX;
	float distY;
	float dist;
	float radius;

	float dX1;
	float dY1;
	float dX2;
	float dY2;
	float direction1;
	float direction2;

	float bX1;
	float bY1;
	float direction3;

	float pX1;
	float pY1;
	float pX2;
	float pY2;
	float direction4;
	float direction5;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene) {
		case TITLE:
			if (keys[DIK_1]) {
				scene =GAME;
			}
			enemyA->SetPosX(bos_->GetPosX());
			enemyA->SetPosY(bos_->GetPosY());
			enemyA->SetVelocityX(4.0f);
			enemyA->SetVelocityY(4.0f);
			enemyB->SetPosX(bos_->GetPosX());
			enemyB->SetPosY(bos_->GetPosY());
			enemyB->SetVelocityX(-4.0f);
			enemyB->SetVelocityY(4.0f);
			player->SetPlayerLife_(3);
			bos_->SetLifeCount(10);
			player->SetIsAlive(true);
			bos_->SetIsShot(true);
			break;
		case GAME:
			enemyA->Move();
			enemyB->Move();
			bos_->Update();
			player->Move(keys, preKeys);
			//Enemyの壁の反射
			distX = enemyA->GetPosX() - enemyB->GetPosX();
			distY = enemyA->GetPosY() - enemyB->GetPosY();
			dist = (distX * distX) + (distY * distY);
			radius = enemyA->GetRadius() + enemyB->GetRadius();
			if (dist <= radius * radius) {
				enemyA->SetVelocityY(enemyA->GetVelocityY() * -1.0f);
				enemyA->SetVelocityY(4.0f);
				enemyB->SetVelocityX(enemyB->GetVelocityX() * -1);
				enemyB->SetVelocityY(-3.0f);
			}

			//Enemyとplayerの弾の当たり判定
			dX1 = enemyA->GetPosX() - player->GetBullet()->GetPosX();
			dY1 = enemyA->GetPosY() - player->GetBullet()->GetPosY();
			dX2 = enemyB->GetPosX() - player->GetBullet()->GetPosX();
			dY2 = enemyB->GetPosY() - player->GetBullet()->GetPosY();
			direction1 = sqrtf(dX1 * dX1 + dY1 * dY1);
			direction2 = sqrtf(dX2 * dX2 + dY2 * dY2);

			//プレイヤーの弾がtrueの時に
			if (player->GetBullet()->GetIsShot() == true) {
				if (direction1 <= bullet->GetRadius() + enemyA->GetRadius()) {
					player->GetBullet()->SetIsShot(false);
					enemyA->SetIsShot(false);
					enemyA->SetPosX(bos_->GetPosX());
					enemyA->SetPosY(bos_->GetPosY());
					enemyA->SetVelocityX(4.0f);
					enemyA->SetVelocityY(4.0f);
					enemyA->SetIsShot(true);

				}
				if (direction2 <= bullet->GetRadius() + enemyB->GetRadius()) {
					player->GetBullet()->SetIsShot(false);
					enemyB->SetIsShot(false);
					enemyB->SetPosX(bos_->GetPosX());
					enemyB->SetPosY(bos_->GetPosY());
					enemyB->SetVelocityX(-4.0f);
					enemyB->SetVelocityY(-4.0f);
					enemyB->SetIsShot(true);
				}
			}

			//Bosとplayerの弾の当たり判定
			bX1 = bos_->GetPosX() - player->GetBullet()->GetPosX();
			bY1 = bos_->GetPosY() - player->GetBullet()->GetPosY();
			direction3 = sqrtf(bX1 * bX1 + bY1 * bY1);

			if (bos_->GetIsShot() == true) {
				if (player->GetBullet()->GetIsShot() == true) {
					if (direction3 <= bullet->GetRadius() + bos_->GetRadius()) {
						player->GetBullet()->SetIsShot(false);
						bos_->SetLifeCount(bos_->GetLifeCount() - 1);
					}

				}
				if (bos_->GetLifeCount() <= 0) {
					bos_->SetIsShot(false);
				}
			}

			//EnemyA,Bとplayerの当たり判定
			pX1 = enemyA->GetPosX() - player->GetPos().x;
			pY1 = enemyA->GetPosY() - player->GetPos().y;
			pX2 = enemyB->GetPosX() - player->GetPos().x;
			pY2 = enemyB->GetPosY() - player->GetPos().y;
			direction4 = sqrtf(pX1 * pX1 + pY1 * pY1);
			direction5 = sqrtf(pX2 * pX2 + pY2 * pY2);

			//プレイヤーの弾がtrueの時に
			if (player->GetIsAlive() == true) {
				if (direction4 <= player->GetRadius() + enemyA->GetRadius()) {
					player->SetPlayerLife_(player->GetPlayerLife() - 1);
					enemyA->SetIsShot(false);
					enemyA->SetPosX(bos_->GetPosX());
					enemyA->SetPosY(bos_->GetPosY());
					enemyA->SetVelocityX(4.0f);
					enemyA->SetVelocityY(4.0f);
					enemyA->SetIsShot(true);

				}
				if (direction5 <= player->GetRadius() + enemyB->GetRadius()) {
					player->SetPlayerLife_(player->GetPlayerLife() - 1);
					enemyB->SetIsShot(false);
					enemyB->SetPosX(bos_->GetPosX());
					enemyB->SetPosY(bos_->GetPosY());
					enemyB->SetVelocityX(-4.0f);
					enemyB->SetVelocityY(-4.0f);
					enemyB->SetIsShot(true);
				}
				if (player->GetPlayerLife() <= 0) {
					player->SetIsAlive(false);
				}
			}
			if (bos_->GetLifeCount() <= 0) {
				scene = CLEAR;
			}
			if (player->GetIsAlive() == false) {
				scene = GAMEOVER;
			}
			break;
		case GAMEOVER:
			if (keys[DIK_1]) {
				scene = TITLE;
			}
			break;
		case CLEAR:
			if (keys[DIK_1]) {
				scene = TITLE;
			}
			break;
		}
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		if (scene == TITLE) {
			Novice::ScreenPrintf(0, 0, "scene:TITLE\n");
			Novice::ScreenPrintf(0, 20, "SPACE\n");
		}

		if (scene == GAME) {
			bos_->Draw();

			if (enemyA->GetIsShot() == true) {
				enemyA->Draw();
			}
			if (enemyB->GetIsShot() == true) {
				enemyB->Draw();
			}
			if (player->GetIsAlive() == true) {
				player->Draw();
			}

			Novice::ScreenPrintf(0, 0, "scene:GAME\n");
			Novice::ScreenPrintf(0, 20, "Bos:%d\n", bos_->GetLifeCount());
			Novice::ScreenPrintf(0, 40, "player:%d\n", player->GetPlayerLife());
			
		}
		if (scene == GAMEOVER) {
			Novice::ScreenPrintf(0, 0, "scene:GAMEOVER\n");
			Novice::ScreenPrintf(0, 20, "SPACE\n");
		}

		if (scene == CLEAR) {
			Novice::ScreenPrintf(0, 0, "scene:CLEAR\n");
			Novice::ScreenPrintf(0, 20, "SPACE\n");
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
