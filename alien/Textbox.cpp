#include "Textbox.h"

Textbox::Textbox(int size,sf::Color color, bool sel)
{
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	isSelected = sel;
	if (sel)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}

void Textbox::setFont(Font& font)
{
	textbox.setFont(font);
}

void Textbox::setPosition(Vector2f pos)
{
	textbox.setPosition(pos);
}

void Textbox::setLimit(bool ToF)
{
	hasLimit = ToF;
}

void Textbox::setLimit(bool ToF, int lim)
{
	hasLimit = ToF;
	limit = lim - 1;
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

string Textbox::getText()
{
	return text.str();
}

Textbox::Textbox()
{

}

void Textbox::drawTo(RenderWindow& window)
{
	window.draw(textbox);
}

void Textbox::typedOn(Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (hasLimit)
			{
				if (text.str().length() <= limit)
				{
					inputLogic(charTyped);
				}
				else if (text.str().length() > limit && charTyped == DELETE_KEY)
				{
					deleteLastChar();
				}
			}
			else
			{
				inputLogic(charTyped);
			}
		}
	}
}


