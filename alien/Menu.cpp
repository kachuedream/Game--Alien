#include "Menu.h"

Menu::Menu(RenderWindow* window)
{
	this->window = window;

	font.loadFromFile("PIXELED.ttf");

	//Text playText("PLAY", font, 25);
	playText.setString("PLAY");
	playText.setFont(font);
	playText.setCharacterSize(25);
	//Text scoreText("SCORE", font, 25);
	scoreText.setString("SCORE");
	scoreText.setFont(font);
	scoreText.setCharacterSize(25);
	//Text aboutText("ABOUT", font, 25);
	aboutText.setString("ABOUT");
	aboutText.setFont(font);
	aboutText.setCharacterSize(25);
	//Text exitText("EXIT", font, 25);
	exitText.setString("EXIT");
	exitText.setFont(font);
	exitText.setCharacterSize(25);

	playText.setPosition(910, 700);
	scoreText.setPosition(900, 775);
	aboutText.setPosition(898, 850);
	exitText.setPosition(915, 925);

	playText.setPosition(910, 700);
	scoreText.setPosition(900, 775);
	aboutText.setPosition(898, 850);
	exitText.setPosition(915, 925);

	background.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	mainTexture.loadFromFile("bgMenu.jpg");
	background.setTexture(&mainTexture);

	htp.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	aboutTexture.loadFromFile("htp.jpg");
	htp.setTexture(&aboutTexture);

	re.setSize(Vector2f(100.f, 100.f));
	re.setPosition(25, 25);
	reTexture.loadFromFile("return.png");
	re.setTexture(&reTexture);

	tF.loadFromFile("PIXELED.ttf");
	Textbox textbox1(50, Color::Black, true);
	textbox1.setFont(tF);
	textbox1.setPosition({ 705,570 });
	textbox1.setLimit(true, 10);
}

void Menu::update(float deltaTime)
{

	if (playText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
	{
		playText.setFillColor(Color::Blue);
	}
	else if (scoreText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
	{
		scoreText.setFillColor(Color::Blue);
	}
	else if (aboutText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
	{
		aboutText.setFillColor(Color::Blue);
	}
	else if (exitText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
	{
		exitText.setFillColor(Color::Blue);
	}
	else
	{
		playText.setFillColor(Color::White);
		scoreText.setFillColor(Color::White);
		aboutText.setFillColor(Color::White);
		exitText.setFillColor(Color::White);
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (exitText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
		{
			window->close();
		}
	}


}

void Menu::render()
{
	window->clear();

	window->draw(background);

	//textbox1->drawTo(window);

	//btn1.drawTo(window);

	window->draw(playText);

	window->draw(scoreText);

	window->draw(aboutText);

	window->draw(exitText);

	window->display();
}
