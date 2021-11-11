#pragma once
#include "AllHeader.h"
#include "Bullet.h"
#include "Item.h"
#include "Player.h"

class Enemy
{
private:
	Sprite enemySprite;

	vector<Enemy> enemies;

	int shootCount;

	Vector2f flyAreaPos;
	Vector2f flyAreaSize;
	Vector2f direction;
	Vector2f targetPos;

	float enemySpeed;

public:

	Enemy(Vector2f spawnPoint, Texture& texture,float speed);

	Vector2f getPos();
	Vector2f getSize();

	FloatRect getGlobalBounds();

	void update(float deltaTime, vector<Bullet>& bullets,vector<Item>&shields,  Texture* bulenTexture,Texture*shieldTexture);
	void render(RenderWindow* window);

};

