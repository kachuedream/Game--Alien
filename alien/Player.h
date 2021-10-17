#pragma once
#include "AllHeader.h"
#include "Animation.h"

class Player
{
private:
	Sprite sprite;
	Texture texture;

	Animation animation;

	float movementSpeed;

	void initVariables();
	void initTexture();

public:
	Player();
	virtual~Player();

	//accessor
	const Vector2f& getPos() const;
	const Vector2f& getSize() const;

	//function
	void move(const float dirX, const float dirY);

	void update(float deltaTime);
	void render(RenderTarget& target);

};

