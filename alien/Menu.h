#pragma once
#include "AllHeader.h"

#define Max_main_menu 4

class Menu
{
private:
	int menuSelected;
	Font font;
	Text menu[Max_main_menu];

public:
	Menu(float width, float height);

	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();

	int MenuPressed()
	{
		return menuSelected;
	}

};

