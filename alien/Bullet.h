#ifndef BULLET_H
#define BULLET_H

#include "AllHeader.h"
#define PLAYER_B 0
#define ENEMY_B 1

class Bullet
{
private:
	Sprite shape;

	Vector2f direction;
	float movementSpeed;

public:
	int tag;
	bool died;

	Bullet();
	Bullet(Texture* texture, Vector2f pos, Vector2f dir, float movement_speed, int tag = PLAYER_B);
	virtual~Bullet();

	//accessor
	FloatRect getGlobalBounds();

	void update(float deltaTime);
	void render(RenderTarget* target);
};

#endif

