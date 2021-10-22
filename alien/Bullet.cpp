#include "Bullet.h"

Bullet::Bullet()
{
	this->died = false;
	this->movementSpeed = 100;
	tag = PLAYER_B;
}

Bullet::Bullet(Texture* texture, Vector2f pos, Vector2f dir, float movement_speed, int tag)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(pos);
	this->direction = dir;
	this->movementSpeed = movement_speed;
	this->died = false;
	this->tag = tag;
}

Bullet::~Bullet()
{

}

FloatRect Bullet::getGlobalBounds() 
{
	return this->shape.getGlobalBounds();
}

void Bullet::update(float deltaTime)
{
	//movement
	this->shape.move(normalize(this->direction) * this->movementSpeed * deltaTime);

	if (shape.getPosition().x < 0 - shape.getGlobalBounds().width || shape.getPosition().x > SCREEN_WIDTH ||
		shape.getPosition().y < 0 - shape.getGlobalBounds().height || shape.getPosition().y > SCREEN_HEIGHT)
	{
		this->died = true;
	}
}

void Bullet::render(RenderTarget* target)
{
	target->draw(this->shape);
}