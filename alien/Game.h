#pragma once
#include "AllHeader.h"
#include "Player.h"
#include "Bullet.h"
#include "Background.h"
#include "Enemy.h"

class Game
{
private:
	RenderWindow* window;

	Player player;

	Texture bulletTexture;
	vector<Bullet> bullets;

	Texture bulenTexture;

	Enemy enemy;
	Texture enemyTexture;
	vector<Enemy> enemies;

	Texture backgroundTexture[6];
	vector<Background>backgrounds;

	float attackCooldown;
	float attackCooldownMax;

public:
	Game(RenderWindow* window);

	void update(float deltaTime);

	void render();
};