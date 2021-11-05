#pragma once
#include "AllHeader.h"
#include "Player.h"
#include "Bullet.h"
#include "Background.h"
#include "Enemy.h"
#include "Item.h"
#include "Textbox.h"
#include "Button.h"

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
	Bullet bulletss;

	//enemy
	Texture enemyTexture;
	vector<Enemy> enemies;

	//background
	Texture backgroundTexture[6];
	vector<Background>backgrounds;

	float attackCooldown;
	float attackCooldownMax;

	//item
	Item item;
	bool shieldOn;
	Sprite barrier;
	Texture shieldTexture;
	Texture barrierTexture;
	vector<Item> shields;
	

public:
	Game(RenderWindow* window);

	void update(float deltaTime);

	void render();
};