#pragma once
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include "Background.h"
#include "Enemy.h"
#include "Item.h"
#include "Textbox.h"
#include "Button.h"
#include "LeaderBoard.h"

class Game : public Scene
{
private:
	//score
	int score;
	Font font;
	Text textScore;

	//player
	string name;
	Player player;
	vector<Player> players;
	Text nameText;

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

	//Logic check
	bool isAlive;

public:
	Game(RenderWindow* window);

	void update(float deltaTime);

	bool checkAlive();

	int getScore();

	void setName(string name);

	string getName();

	void reset();

	void render();
};