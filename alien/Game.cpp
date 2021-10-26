#include "Game.h"

Game::Game(RenderWindow* window)
{
	this->window = window;
	attackCooldownMax = 0.1;
	attackCooldown = attackCooldownMax;
	bulletTexture.loadFromFile("bullets.png");
	enemyTexture.loadFromFile("enemy1.png");
	bulenTexture.loadFromFile("bulen1.png");
	
	//score
	score = 0;
	font.loadFromFile("GAMERIA.ttf");
	textScore.setFont(font);
	textScore.setFillColor(Color::White);
	textScore.setCharacterSize(50);
	textScore.setPosition(Vector2f(30,20));
	textScore.setString("Score "+to_string(score));

	//item
	doubleTexture.loadFromFile("double.png");
	shieldTexture.loadFromFile("shield.png");

	//background
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

	for (int i = 0; i < 5; i++)
	{
		enemies.push_back(Enemy(Vector2f(1920, rand() % SCREEN_HEIGHT), enemyTexture));
	}

	gameOver = false;
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

	//update bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).update(deltaTime);
		if (bullets.at(i).died)
		{
			bullets.erase(bullets.begin() + i);
		}
	}

	//update shield
	for (int i = 0; i < shields.size(); i++)
	{
		shields.at(i).update(deltaTime);
		if (shields.at(i).died)
		{
			shields.erase(shields.begin() + i);
		}
	}

	//update double
	for (int i = 0; i < doubles.size(); i++)
	{
		doubles.at(i).update(deltaTime);
		if (doubles.at(i).died)
		{
			doubles.erase(doubles.begin() + i);
		}
	}

	//update enemies
	for (int e = 0; e < enemies.size(); e++)
	{
		enemies.at(e).update(deltaTime, bullets, shields,doubles, &bulenTexture,&shieldTexture,&doubleTexture);
		for (size_t b = 0; b < bullets.size(); b++)
		{
			if (bullets[b].getGlobalBounds().intersects(enemies[e].getGlobalBounds()) && bullets[b].tag!= ENEMY_B)
			{
				enemies.erase(enemies.begin() + e);
				enemies.push_back(Enemy(Vector2f(1920, rand() % SCREEN_HEIGHT), enemyTexture));
				score += 100;
				textScore.setString("Score " + to_string(score));
				break;
			}
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

	//render shield
	for (int i = 0; i < shields.size(); i++)
	{
		shields.at(i).render(window);
	}

	//render double
	for (int i = 0; i < doubles.size(); i++)
	{
		doubles.at(i).render(window);
	}

	//render enemy
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).render(window);
	}

	this->player.render(*window);

	window->draw(textScore);

}