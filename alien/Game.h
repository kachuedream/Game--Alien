#pragma once
#include "AllHeader.h"
#include "Player.h"
#include "Bullet.h"
#include "Background.h"
#include "Enemy.h"
#include "Item.h"

class Game
{
private:
	RenderWindow* window;

	Player player;
	vector<Player> players;

	Texture bulletTexture;
	vector<Bullet> bullets;

	Texture bulenTexture;

	Texture enemyTexture;
	vector<Enemy> enemies;

	Texture backgroundTexture[6];
	vector<Background>backgrounds;

	float attackCooldown;
	float attackCooldownMax;

	Texture doubleTexture;
	Texture shieldTexture;
	vector<Item> shields;
	vector<Item> doubles;

	bool gameOver;

public:
	Game(RenderWindow* window);

	void update(float deltaTime);

	void render();
};