#pragma once
#include "Scene.h"
#include "Textbox.h"

class Menu : public Scene
{
private:
	Font font;

	Text playText;
	Text scoreText;
	Text aboutText;
	Text exitText;

	//set menubackground
	RectangleShape background;
	Texture mainTexture;

	//set about
	RectangleShape htp;
	Texture aboutTexture;

	//set return
	RectangleShape re;
	Texture reTexture;

	//Textbox
	Font tF;
	Textbox textbox1;

public:
	Menu(RenderWindow* window);

	void update(float deltaTime);

	void render();

};
