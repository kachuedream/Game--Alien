#include "Game.h"

Game::Game(RenderWindow* window)
{
	this->window = window;
	attackCooldownMax = 0.1;
	attackCooldown = attackCooldownMax;
	bulletTexture.loadFromFile("bullets.png");
	enemyTexture.loadFromFile("enemy2.png");
	//bossTexture.loadFromFile("boss.png");
	bulenTexture.loadFromFile("bulen1.png");
	barrierTexture.loadFromFile("barrier.png");

	//score
	score = 0;
	font.loadFromFile("GAMERIA.ttf");
	textScore.setFont(font);
	textScore.setFillColor(Color::White);
	textScore.setCharacterSize(50);
	textScore.setPosition(Vector2f(30, 20));
	textScore.setString("Score " + to_string(score));

	//You can remove if doesn't need it
	nameText.setFont(font);
	nameText.setFillColor(Color::White);
	nameText.setCharacterSize(50);
	nameText.setPosition(Vector2f(800, 20));

	//items
	shieldTexture.loadFromFile("shield1.png");
	shieldOn = false;

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

	for (int i = 0; i < 4; i++)
	{
		enemies.push_back(Enemy(Vector2f(1920, rand() % SCREEN_HEIGHT), enemyTexture,300));
	}

	barrier.setTexture(barrierTexture);

	isAlive = 1;

	inGameTime = 0;

}



void Game::update(float deltaTime)
{
	inGameTime += deltaTime;
	player.update(deltaTime);
	barrier.setPosition(player.getPos());
	attackCooldown += deltaTime;
	if (Mouse::isButtonPressed(Mouse::Left) && attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0;
		Vector2f offset = (player.getSize() / 2.f) + Vector2f(0.f, -10.f);
		bullets.push_back(Bullet(&bulletTexture, player.getPos() + offset, Vector2f(1.f, 0.f), 800.f));
	}

	//update bullets
	for (int b = 0; b < bullets.size(); b++)
	{
		bullets.at(b).update(deltaTime);
		if (bullets.at(b).died)
		{
			bullets.erase(bullets.begin() + b);
			continue;
		}
		if (player.getGlobalBounds().intersects(bullets[b].getGlobalBounds()) && bullets[b].tag == ENEMY_B)
		{
			if (shieldOn)
			{
				bullets.erase(bullets.begin() + b);
				shieldOn = false;
			}
			//End Game
			else
			{
				isAlive = 0;
			}
		}
	}

	//update shield
	for (int s = 0; s < shields.size(); s++)
	{
		shields.at(s).update(deltaTime);
		if (shields.at(s).died)
		{
			shields.erase(shields.begin() + s);
			continue;
		}
		if (player.getGlobalBounds().intersects(shields[s].getGlobalBounds()))
		{
			shields.erase(shields.begin() + s);
			shieldOn = true;
		}
	}

	//update enemies
	for (int e = 0; e < enemies.size(); e++)
	{
		enemies.at(e).update(deltaTime, bullets, shields, &bulenTexture, &shieldTexture);
		for (size_t b = 0; b < bullets.size(); b++)
		{
			if (inGameTime >= 0 && inGameTime <= 60)
			{
				if (bullets[b].getGlobalBounds().intersects(enemies[e].getGlobalBounds()) && bullets[b].tag != ENEMY_B)
				{
					enemies.erase(enemies.begin() + e);
					enemies.push_back(Enemy(Vector2f(1920, rand() % SCREEN_HEIGHT), enemyTexture, 300));
					score += 100;
					textScore.setString("Score " + to_string(score));
					//multiplier = 0;
					break;
				}
			}
			else if (inGameTime >60 && inGameTime <=120)
			{
				if (bullets[b].getGlobalBounds().intersects(enemies[e].getGlobalBounds()) && bullets[b].tag != ENEMY_B)
				{
					enemies.erase(enemies.begin() + e);
					enemies.push_back(Enemy(Vector2f(1920, rand() % SCREEN_HEIGHT), enemyTexture, 400));
					score += 100;
					textScore.setString("Score " + to_string(score));
					break;
				}
			}
			else if (inGameTime > 120 && inGameTime <=180)
			{
				if (bullets[b].getGlobalBounds().intersects(enemies[e].getGlobalBounds()) && bullets[b].tag != ENEMY_B)
				{
					enemies.erase(enemies.begin() + e);
					enemies.push_back(Enemy(Vector2f(1920, rand() % SCREEN_HEIGHT), enemyTexture, 500));
					score += 100;
					textScore.setString("Score " + to_string(score));
					break;
				}
			}
			else if (inGameTime > 180)
			{
				if (bullets[b].getGlobalBounds().intersects(enemies[e].getGlobalBounds()) && bullets[b].tag != ENEMY_B)
				{
					enemies.erase(enemies.begin() + e);
					enemies.push_back(Enemy(Vector2f(1920, rand() % SCREEN_HEIGHT), enemyTexture, 600));
					score += 100;
					textScore.setString("Score " + to_string(score));
					break;
				}
			}
			
		}
	}

	//update background
	for (Background& background : backgrounds)
		background.update(deltaTime);
}

bool Game::checkAlive()
{
	return isAlive;
}

int Game::getScore()
{
	return this->score;
}

void Game::setName(string name)
{
	this->name = name;
	nameText.setString(name);
}

string Game::getName()
{
	return this->name;
}

void Game::reset()
{
	inGameTime = 0;
	score = 0;
	players.clear();
	enemies.clear();
	bullets.clear();
	shields.clear();
	isAlive = 1;
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

	//render enemy
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).render(window);
	}

	if (shieldOn)
		window->draw(barrier);


	this->player.render(*window);

	//window->draw(nameText);

	window->draw(textScore);

}