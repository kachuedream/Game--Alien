#pragma once
#include "AllHeader.h"
#include"Enemy.h"
class BulEn
{
private:
	Sprite bulenSprite;

	Vector2f AreaBulenPos;
	Vector2f AreaBulenSize;
	Vector2f targetPosEne;

	Vector2f direction;

	float speed;

public:
	BulEn();

	Enemy enemy;

	bool bulendied;
	BulEn(Vector2f spawnPoint, Texture& texture);

	void update(float deltaTime);
	void render(RenderWindow* window);

};