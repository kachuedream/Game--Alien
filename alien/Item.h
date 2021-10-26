#pragma once

#include "AllHeader.h"

class Item
{
private:
	Sprite shape;

	Vector2f direction;
	float movementSpeed;

public:
	int tag;
	bool died;

	Item();
	Item(Texture* texture, Vector2f pos, Vector2f dir, float movement_speed);
	virtual~Item();

	//accessor
	FloatRect getGlobalBounds();

	void update(float deltaTime);
	void render(RenderTarget* target);
};



