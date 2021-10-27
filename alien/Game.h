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

	//score
	int score;
	Font font;
	Text textScore;

	//player
	Player player;
	vector<Player> players;

	//bullet
	Texture bulletTexture;
	Texture bulenTexture;
	vector<Bullet> bullets;

	//enemy
	Texture enemyTexture;
	vector<Enemy> enemies;

	//background
	Texture backgroundTexture[6];
	vector<Background>backgrounds;

	float attackCooldown;
	float attackCooldownMax;

	//item
	Texture doubleTexture;
	Texture shieldTexture;
	vector<Item> shields;
	vector<Item> doubles;

	bool gameOver;
	bool shieldOn;

public:
	Game(RenderWindow* window);

	void update(float deltaTime);

	void render();
};