#include "Button.h"

Button::Button()
{

}

Button::Button(string t, Vector2f size, int charSize, Color bgColor, Color textColor)
{
	text.setString(t);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(bgColor);
}

void Button::setFont(Font& font)
{
	text.setFont(font);
}

void Button::setBackColor(Color color)
{
	button.setFillColor(color);
}

void Button::setTextColor(Color color)
{
	text.setFillColor(color);
}

void Button::setPosition(Vector2f pos)
{
	button.setPosition(pos);

	float xPos = (pos.x + button.getLocalBounds().width / 4) - (text.getLocalBounds().width / 2);
	float yPos = (pos.y + button.getLocalBounds().height / 4) - (text.getLocalBounds().height / 2);
	text.setPosition({ xPos,yPos });
}

void Button::drawTo(RenderWindow& window)
{
	window.draw(button);
	window.draw(text);
}

bool Button::isMouseOver(RenderWindow& window)
{
	float mouseX = Mouse::getPosition(window).x;
	float mouseY = Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;
	
	float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
	{
		return true;
	}
	return false;
}
