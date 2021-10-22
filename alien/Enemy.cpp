#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2f spawnPoint, Texture& texture)
{
	this->enemySprite.setTexture(texture);
	this->enemySprite.scale(0.3f, 0.3f);
	this->enemySprite.setPosition(spawnPoint);

	flyAreaPos = Vector2f(1000.f, 0.f);

	// subtract enemy size so enemy won't get out of screen
	flyAreaSize = Vector2f(960.f - enemySprite.getGlobalBounds().width, 1080.f - enemySprite.getGlobalBounds().height);

	speed = 300;

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

void Enemy::update(float deltaTime, vector<Bullet>& bullets, Texture* bulenTexture)
{
	direction = normalize(targetPos - enemySprite.getPosition());
	enemySprite.move(direction * speed * deltaTime);

	if (distance(enemySprite.getPosition(), targetPos) < 10.f)
	{
		targetPos.x = rand() % int(flyAreaSize.x) + flyAreaPos.x;
		targetPos.y = rand() % int(flyAreaSize.y) + flyAreaPos.y;
		bullets.push_back(Bullet(bulenTexture, enemySprite.getPosition(), Vector2f(-1.f, 0.f), 200.f, ENEMY_B));
	}
}

void Enemy::render(RenderWindow* window)
{
	window->draw(enemySprite);
}