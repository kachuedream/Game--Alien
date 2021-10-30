#pragma once
#include "Allheader.h"

class Scene
{
protected:
	RenderWindow* window;

public:
	inline Scene() { window = nullptr; }

	virtual void update();
	virtual void render();
};