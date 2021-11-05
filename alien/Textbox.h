#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include <sstream>
#include "AllHeader.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
private:
	Text textbox;
	ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped)
	{
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
		{
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DELETE_KEY)
		{
			if (text.str().length() > 0)
			{
				deleteLastChar();
			}
		}
		textbox.setString(text.str() + "_");
	}

	void deleteLastChar()
	{
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		text.str("");
		text << newT;

		textbox.setString(text.str());
	}

public:
	string getText();

	Textbox();

	Textbox(int size, sf:: Color color, bool sel);

	void setFont(Font& font);

	void setPosition(Vector2f pos);

	void setLimit(bool ToF);

	void setLimit(bool ToF, int lim);

	void setSelected(bool sel);

	void drawTo(RenderWindow& window);

	void typedOn(Event input);
};



