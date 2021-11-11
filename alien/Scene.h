#pragma once
#include "AllHeader.h"

class Scene
{
protected:
	RenderWindow* window;
public:
	static int index;

	virtual inline void update(float deltaTime) {}
	virtual inline void render() {}
};
