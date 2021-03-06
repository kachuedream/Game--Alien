#include "Enemy.h"


Enemy::Enemy(Vector2f spawnPoint, Texture& texture,float speed)
{
	this->enemySprite.setTexture(texture);
	this->enemySprite.scale(0.15f, 0.15f);
	this->enemySprite.setPosition(spawnPoint);

	flyAreaPos = Vector2f(1000.f, 0.f);

	shootCount = 0;

	// subtract enemy size so enemy won't get out of screen
	flyAreaSize = Vector2f(920.f - enemySprite.getGlobalBounds().width, 1080.f - enemySprite.getGlobalBounds().height);

	enemySpeed = 300;
	this->enemySpeed = speed;

	targetPos.x = rand() % int(flyAreaSize.x) + flyAreaPos.x ;
	targetPos.y = rand() % int(flyAreaSize.y) + flyAreaPos.y ;
}

Vector2f Enemy::getPos()
{
	return this->enemySprite.getPosition();
}

Vector2f Enemy::getSize()
{
	return Vector2f(enemySprite.getGlobalBounds().width, enemySprite.getGlobalBounds().height);
}

FloatRect Enemy::getGlobalBounds() 
{
	return this->enemySprite.getGlobalBounds();
}

void Enemy::update(float deltaTime, vector<Bullet>& bullets, vector<Item>& shields, Texture* bulenTexture, Texture* shieldTexture)
{
	direction = normalize(targetPos - enemySprite.getPosition());
	enemySprite.move(direction * enemySpeed * deltaTime);

	if (distance(enemySprite.getPosition(), targetPos) < 10.f )
	{
		targetPos.x = rand() % int(flyAreaSize.x) + flyAreaPos.x;
		targetPos.y = rand() % int(flyAreaSize.y) + flyAreaPos.y;
		shootCount++;

			if (shootCount % 3 == 0)
				shields.push_back(Item(shieldTexture, enemySprite.getPosition(), Vector2f(-1.f, 0.f), 300.f));

			else
			{
				bullets.push_back(Bullet(bulenTexture, enemySprite.getPosition(), Vector2f(-1.f, 0.f), 800.f, ENEMY_B));
			}

	}
	
}

void Enemy::render(RenderWindow* window)
{
	window->draw(enemySprite);
}