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
//#include "Game.h"

//int main()
//{
//	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Fullscreen);
//		window.setVerticalSyncEnabled(true);
//		srand(time(0));

//		Font font;
//		font.loadFromFile("PIXELED.ttf");

//		Text playText("PLAY", font, 25);
//		Text scoreText("SCORE", font, 25);
//		Text aboutText("ABOUT", font, 25);
//		Text exitText("EXIT", font, 25);

//		playText.setPosition(910, 700);
//		scoreText.setPosition(900, 775);
//		aboutText.setPosition(898, 850);
//		exitText.setPosition(915, 925);

//		//set menubackground
//		RectangleShape background;
//		background.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
//		Texture mainTexture;
//		mainTexture.loadFromFile("bgMenu.jpg");
//		background.setTexture(&mainTexture);

//		//set about
//		RectangleShape htp;
//		htp.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
//		Texture aboutTexture;
//		aboutTexture.loadFromFile("htp.jpg");
//		htp.setTexture(&aboutTexture);

//		//set return
//		RectangleShape re;
//		re.setSize(Vector2f(100.f,100.f));
//		re.setPosition(25,25);
//		Texture reTexture;
//		reTexture.loadFromFile("return.png");
//		re.setTexture(&reTexture);

//		Clock clock;
//		float deltaTime = 0;

//		//Textbox
//		Font tF;
//		tF.loadFromFile("PIXELED.ttf");
//		Textbox textbox1(50,Color::Black,true);
//		textbox1.setFont(tF);
//		textbox1.setPosition({ 705,570 });
//		textbox1.setLimit(true, 10);

//		//Button
//		/*Font bF;
//		bF.loadFromFile("PIXELED.ttf");
//		Button btn1("Click me", { 200,50 },20,Color::Green,Color::Black);
//		btn1.setPosition({ 1000,400 });
//		btn1.setFont(bF);*/

//		while (window.isOpen())
//		{
//			MENU:
//			Event event;

//			if (Keyboard::isKeyPressed(Keyboard::Return))
//			{
//				textbox1.setSelected(true);
//			}
//			else if (Keyboard::isKeyPressed(Keyboard::Escape))
//			{
//				textbox1.setSelected(false);
//			}

//			while (window.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//					window.close();

//				if (event.type == Event::TextEntered)
//					textbox1.typedOn(event);

//				/*if(event.type == Event::MouseMoved)
//					if (btn1.isMouseOver(window))
//					{
//						btn1.setBackColor(Color::White);
//					}
//					else
//					{
//						btn1.setBackColor(Color::Blue);
//					}
//					break;
//					if (event.type == Event::MouseButtonPressed)
//						if (btn1.isMouseOver(window))
//						{
//							std::cout << "You clicked the button\n";
//						}*/
				
//			}

//			if (playText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//			{
//				playText.setFillColor(Color::Blue);
//			}
//			else if (scoreText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//			{
//				scoreText.setFillColor(Color::Blue);
//			}
//			else if (aboutText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//			{
//				aboutText.setFillColor(Color::Blue);
//			}
//			else if (exitText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//			{
//				exitText.setFillColor(Color::Blue);
//			}
//			else
//			{
//				playText.setFillColor(Color::White);
//				scoreText.setFillColor(Color::White);
//				aboutText.setFillColor(Color::White);
//				exitText.setFillColor(Color::White);
//			}

//			if (Mouse::isButtonPressed(Mouse::Left))
//			{
//				if (playText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//				{
//					Game game(&window);
//					deltaTime = 0;
//					while (window.isOpen())
//					{
//						deltaTime = clock.restart().asSeconds();
//						Event ev;
//						while (window.pollEvent(ev))
//						{
//							//deltaTime = 0;
//							if (ev.type == Event::Closed)
//								window.close();
//							else if (ev.type == Event::KeyPressed)
//							{
//								if (ev.key.code == Keyboard::Escape)
//								{
//									window.close();
//								}
//							}
//						}
//						game.update(deltaTime);
						
//						window.clear();
						
//						game.render();
						
//						window.display();

//					}
//				}
//				else if (scoreText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//				{

//				}
//				else if (aboutText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//				{
//					while (window.isOpen())
//					{
//						Event aevent;
//						while (window.pollEvent(aevent))
//						{
//							if (aevent.type == Event::Closed)
//							{
//								window.close();
//							}
//							if (aevent.type == Event::KeyPressed)
//							{
//								if (aevent.key.code == Keyboard::Escape)
//								{
//									window.close();
//								}
//							}
//							if (re.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)&& Mouse::isButtonPressed(Mouse::Left))
//							{
//								goto MENU;
//							}
//						}
//						window.clear();

//						window.draw(htp);

//						window.draw(re);

//						window.display();
//					}
//				}
//				else if (exitText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
//				{
//					window.close();
//				}
//			}

//			window.clear();

//			window.draw(background);

//			textbox1.drawTo(window);

//			//btn1.drawTo(window);

//			window.draw(playText);

//			window.draw(scoreText);

//			window.draw(aboutText);

//			window.draw(exitText);

//			window.display();
//		}
//		return 0;
//}