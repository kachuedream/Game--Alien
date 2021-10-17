#include "Game.h"

Game::Game(RenderWindow* window)
{
	this->window = window;
	attackCooldownMax = 0.1;
	attackCooldown = attackCooldownMax;
	bulletTexture.loadFromFile("bullets.png");
	enemyTexture.loadFromFile("enemy.png");
	bulenTexture.loadFromFile("bulletenemy.png");

	backgroundTexture[0].loadFromFile("sky.jpg");
	backgroundTexture[1].loadFromFile("moon.png");
	backgroundTexture[2].loadFromFile("star1.png");
	backgroundTexture[3].loadFromFile("star2.png");
	backgroundTexture[4].loadFromFile("land2.png");
	backgroundTexture[5].loadFromFile("land1.png");

	backgrounds.push_back(Background(&backgroundTexture[0], 0.f));
	backgrounds.push_back(Background(&backgroundTexture[1], 0.f));
	backgrounds.push_back(Background(&backgroundTexture[2], -130.f));
	backgrounds.push_back(Background(&backgroundTexture[3], 100.f));
	backgrounds.push_back(Background(&backgroundTexture[4], -100.f));
	backgrounds.push_back(Background(&backgroundTexture[5], 70.f));

	for (int i = 0; i < 4; i++)
	{
		enemies.push_back(Enemy(Vector2f(1920, 0), enemyTexture));
	}
}

void Game::update(float deltaTime)
{
	player.update(deltaTime);
	attackCooldown += deltaTime;
	if (Mouse::isButtonPressed(Mouse::Left) && attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0;
		Vector2f offset = (player.getSize() / 2.f) + Vector2f(0.f, -10.f);
		bullets.push_back(Bullet(&bulletTexture, player.getPos() + offset, Vector2f(1.f, 0.f), 1000.f));
	}


	//update enemies
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).update(deltaTime, bullets, &bulenTexture);
	}

	//update bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).update(deltaTime);
		if (bullets.at(i).died)
		{
			bullets.erase(bullets.begin() + i);
		}
	}

	//update background
	for (Background& background : backgrounds)
		background.update(deltaTime);
}

void Game::render()
{
	//render background
	for (Background& background : backgrounds)
		background.draw(*window);

	//render bullet
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).render(window);
	}

	//render enemy
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).render(window);
	}

	////render bulen
	//for (int i = 0; i < bulens.size(); i++)
	//{
	//	bulens.at(i).render(window);
	//}

	this->player.render(*window);
}