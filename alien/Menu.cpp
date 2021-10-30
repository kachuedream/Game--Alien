#include "Menu.h"

Menu::Menu(float width, float height)
{
	font.loadFromFile("GAMERIA.ttf");

	//PLAY
	menu[0].setFont(font);
	menu[0].setFillColor(Color::White);
	menu[0].setString("PLAY");
	menu[0].setCharacterSize(100);
	menu[0].setPosition(400, 200);

	//SCORE
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("SCORE");
	menu[1].setCharacterSize(100);
	menu[1].setPosition(400, 300);

	//EXIT
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("EXIT");
	menu[2].setCharacterSize(100);
	menu[2].setPosition(400, 400);

	menuSelected = -1;
}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu;i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if(menuSelected -1 >= 0)
	{
		menu[menuSelected].setFillColor(Color::White);

		menuSelected--;
		if (menuSelected == -1)
		{
			menuSelected = 2;
		}
		menu[menuSelected].setFillColor(Color::Blue);
	}
}

void Menu::moveDown()
{
	if (menuSelected + 1 <= Max_main_menu)
	{
		menu[menuSelected].setFillColor(Color::White);

		menuSelected ++;
		if (menuSelected == 3)
		{
			menuSelected = 0;
		}
		menu[menuSelected].setFillColor(Color::Blue);
	}
}
