#pragma once
#include "AllHeader.h"

class Background
{
private:
	RectangleShape body[2];
	Vector2f position;
	Vector2f size;

	float speed;

public:
	Background(Texture* texture, float speed);

	void update(float deltaTime);
	void draw(RenderWindow& window);
};

