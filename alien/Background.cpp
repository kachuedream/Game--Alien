#include "Background.h"

Background::Background(Texture* texture, float speed)
{
	this->speed = speed;
	this->size = Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);

	body[0].setSize(size);
	body[1].setSize(size);
	body[0].setTexture(texture);
	body[1].setTexture(texture);

	if (speed < 0)
		body[1].setPosition(size.x - 3.f, 0.f);
	else
		body[1].setPosition(-size.x + 3.f, 0.f);
}

void Background::update(float deltaTime)
{
	for (int i = 0; i < 2; i++)
	{
		position = body[i].getPosition();

		body[i].move(speed * deltaTime, 0);

		if (position.x + size.x < 0 && speed < 0)
			body[i].setPosition(size.x - 7.f, position.y);
		else if (position.x > size.x && speed > 0)
			body[i].setPosition(-size.x + 7.f, position.y);
	}
}

void Background::draw(RenderWindow& window)
{
	window.draw(body[0]);
	window.draw(body[1]);
}
