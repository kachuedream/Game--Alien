#include "Player.h"

using namespace sf;

void Player::initVariables()
{
	this->movementSpeed = 400.f;
}

void Player::initTexture()
{
	//load a texture from file
	texture.loadFromFile("char.png");

	//set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//resize the sprite
	this->sprite.scale(0.2f, 0.2f);

	animation.init(&texture, Vector2u(2, 2), 0.2f);
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
}

Player::~Player()
{

}

const Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const Vector2f& Player::getSize() const
{
	return Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, movementSpeed * dirY);
}

void Player::update(float deltaTime)
{
	Vector2f direction;
	if (Keyboard::isKeyPressed(Keyboard::W) && getPos().y > 0)
		direction.y -= 1;
	if (Keyboard::isKeyPressed(Keyboard::A) && getPos().x > 0)
		direction.x -= 1;
	if (Keyboard::isKeyPressed(Keyboard::S) && getPos().y < SCREEN_HEIGHT-sprite.getGlobalBounds().height)
		direction.y += 1;
	if (Keyboard::isKeyPressed(Keyboard::D) && getPos().x < SCREEN_WIDTH - sprite.getGlobalBounds().height)
		direction.x += 1;
	sprite.move(direction * movementSpeed * deltaTime);

	int row = 1;
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		row = 0;
	}

	animation.update(row, deltaTime, true);
	sprite.setTextureRect(animation.uvRect);
}

void Player::render(RenderTarget& target)
{
	target.draw(this->sprite);
}