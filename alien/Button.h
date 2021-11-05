#pragma once
#include "AllHeader.h"

class Button
{
private:
	RectangleShape button;
	Text text;

public:
	Button();

	Button(string t, Vector2f size, int charSize, Color bgColor, Color textColor);

	void setFont(Font& font);

	void setBackColor(Color color);

	void setTextColor(Color color);

	void setPosition(Vector2f pos);

	void drawTo(RenderWindow& window);

	bool isMouseOver(RenderWindow& window);

};

