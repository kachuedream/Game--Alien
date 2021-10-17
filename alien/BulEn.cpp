#include "BulEn.h"
#include "Enemy.h"

BulEn::BulEn()
{
}

BulEn::BulEn(Vector2f spawnPoint, Texture& texture)
{
	this->bulenSprite.setTexture(texture);
	this->bulenSprite.scale(1.f, 1.f);
	this->bulenSprite.setPosition(spawnPoint);

	AreaBulenPos = Vector2f(0.f, 0.f);

	// subtract enemy size so enemy won't get out of screen
	AreaBulenSize = Vector2f(960.f - bulenSprite.getGlobalBounds().width, 1080.f - bulenSprite.getGlobalBounds().height);

	speed = 500;

	targetPosEne.y = rand() % int(AreaBulenSize.y) + AreaBulenPos.y;
	targetPosEne.y = rand() % int(AreaBulenSize.y) + AreaBulenPos.y;
}

void BulEn::update(float deltaTime)
{
	direction = normalize(targetPosEne - bulenSprite.getPosition());
	bulenSprite.move(direction * speed * deltaTime);

}

void BulEn::render(RenderWindow* window)
{
	window->draw(bulenSprite);
}