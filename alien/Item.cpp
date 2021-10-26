#include "Item.h"

Item::Item()
{
	this->died = false;
	this->movementSpeed = 100;
}

Item::Item(Texture* texture, Vector2f pos, Vector2f dir, float movement_speed)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(pos);
	this->direction = dir;
	this->movementSpeed = movement_speed;
	this->died = false;
}

Item::~Item()
{

}

FloatRect Item::getGlobalBounds()
{
	return shape.getGlobalBounds();
}

void Item::update(float deltaTime)
{
	//movement
	shape.move(normalize(direction) * movementSpeed * deltaTime);

	if (shape.getPosition().x < 0 - shape.getGlobalBounds().width || shape.getPosition().x > SCREEN_WIDTH ||
		shape.getPosition().y < 0 - shape.getGlobalBounds().height || shape.getPosition().y > SCREEN_HEIGHT)
	{
		died = true;
	}
}

void Item::render(RenderTarget* target)
{
	target->draw(shape);
}