#pragma once
#include "AllHeader.h"
#include "Bullet.h"

class Enemy
{
private:
	Sprite enemySprite;

	Vector2f flyAreaPos;
	Vector2f flyAreaSize;
	Vector2f direction;
	Vector2f targetPos;
	float speed;

public:
	Enemy();
	Enemy(Vector2f spawnPoint, Texture& texture);

	Vector2f getPos();
	Vector2f getSize();

	void update(float deltaTime, vector<Bullet>& bullets, Texture* bulenTexture);
	void render(RenderWindow* window);

};

