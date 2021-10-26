#pragma once
#include "AllHeader.h"
#include "Bullet.h"
#include "Item.h"

class Enemy
{
private:
	Sprite enemySprite;

	int shootCount;

	Vector2f flyAreaPos;
	Vector2f flyAreaSize;
	Vector2f direction;
	Vector2f targetPos;
	float speed;

public:

	Enemy(Vector2f spawnPoint, Texture& texture);

	Vector2f getPos();
	Vector2f getSize();

	FloatRect getGlobalBounds();

	void update(float deltaTime, vector<Bullet>& bullets,vector<Item>&shields, vector<Item>& doubles, Texture* bulenTexture,Texture*shieldTexture, Texture* doubleTexture);
	void render(RenderWindow* window);

};

