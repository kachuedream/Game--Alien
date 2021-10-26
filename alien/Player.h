#pragma once
#include "AllHeader.h"
#include "Animation.h"
#include "Bullet.h"

class Player
{
private:
	Sprite sprite;
	Texture texture;

	Animation animation;

	float movementSpeed;

	void initVariables();
	void initTexture();

	vector<Player> players;
	vector<Bullet> bullets;

	FloatRect getGlobalBounds();

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

