#include "Game.h"
#include "Menu.h"

//int main()
//{
//	//make a menu
//	RenderWindow MENU(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Main Menu", Style::Fullscreen);
//	Menu menu(MENU.getSize().x, MENU.getSize().y);
//
//	//set background
//	RectangleShape background;
//	background.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
//	Texture mainTexture;
//	mainTexture.loadFromFile("bgMenu.jpg");
//	background.setTexture(&mainTexture);
//
//	//photo to the game
//	RectangleShape Pbackground;
//	Pbackground.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
//	Texture back_texture;
//	back_texture.loadFromFile("123.jpg");
//	Pbackground.setTexture(&back_texture);
//
//	//photo to the score
//	RectangleShape Sbackground;
//	Sbackground.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
//	Texture score_texture;
//	score_texture.loadFromFile("123.jpg");
//	Sbackground.setTexture(&score_texture);
//
//	//photo to the about
//	RectangleShape Abackground;
//	Abackground.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
//	Texture about_texture;
//	about_texture.loadFromFile("htp.jpg");
//	Abackground.setTexture(&about_texture);
//
//	Clock clock;
//	float deltaTime = 0;
//
//	while (MENU.isOpen())
//	{
//		Event event;
//		while (MENU.pollEvent(event))
//		{
//			if (event.type==Event::Closed)
//			{
//				MENU.close();
//			}
//			if (event.type == Event::KeyReleased)
//			{
//				if (event.key.code == Keyboard::Up)
//				{
//					menu.moveUp();
//					break;
//				}
//				if (event.key.code == Keyboard::Down)
//				{
//					menu.moveDown();
//					break;
//				}
//				if (event.key.code == Keyboard::Return)
//				{
//					RenderWindow Score(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SCORE", Style::Fullscreen);
//					RenderWindow Exit(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "EXIT", Style::Fullscreen);
//					RenderWindow About(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ABOUT", Style::Fullscreen);
//					RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Fullscreen);
//					window.setVerticalSyncEnabled(true);
//					srand(time(0));
//					Game game(&window);
//
//					int x = menu.MenuPressed();
//					if (x == 0)
//					{
//						while (window.isOpen())
//						{
//							deltaTime = clock.restart().asSeconds();
//							Event ev;
//							while (window.pollEvent(ev))
//							{
//								if (ev.type == Event::Closed)
//									window.close();
//								else if (ev.type == Event::KeyPressed)
//								{
//									if (ev.key.code == Keyboard::Escape)
//									{
//										window.close();
//									}
//								}
//							}
//
//							Score.close();
//
//							About.close();
//
//							Exit.close();
//
//							MENU.clear();
//
//							game.update(deltaTime);
//
//							window.clear();
//
//							game.render();
//
//							window.display();
//
//						}
//					}
//					if (x == 1)
//					{
//						while (Score.isOpen())
//						{
//							Event aevent;
//							while (Score.pollEvent(aevent))
//							{
//								if (aevent.type == Event::Closed)
//								{
//									Score.close();
//								}
//								if (aevent.type == Event::KeyPressed)
//								{
//									if (aevent.key.code == Keyboard::Escape)
//									{
//										Score.close();
//									}
//								}
//							}
//							window.close();
//
//							About.close();
//
//							Exit.close();
//
//							Score.clear();
//
//							Score.draw(Sbackground);
//
//							Score.display();
//						}
//					}
//					if (x == 2)
//					{
//						while (About.isOpen())
//						{
//							Event aevent;
//							while (About.pollEvent(aevent))
//							{
//								if (aevent.type == Event::Closed)
//								{
//									About.close();
//								}
//								if (aevent.type == Event::KeyPressed)
//								{
//									if (aevent.key.code == Keyboard::Escape)
//									{
//										About.close();
//									}
//								}
//							}
//							window.close();
//
//							Score.close();
//
//							Exit.close();
//
//							About.clear();
//
//							About.draw(Abackground);
//
//							About.display();
//						}
//					}
//					if (x == 3)
//						MENU.close();
//						break;
//				}
//			}
//		}
//
//		MENU.clear();
//
//		MENU.draw(background);
//
//		menu.draw(MENU);
//
//		MENU.display();
//	}
//	return 0;
//}


int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Fullscreen);
		window.setVerticalSyncEnabled(true);
		srand(time(0));
		Game game(&window);

		Font font;
		font.loadFromFile("GAMERIA.ttf");

		Text playText("PLAY", font, 100);
		Text scoreText("SCORE", font, 100);
		Text aboutText("ABOUT", font, 100);
		Text exitText("EXIT", font, 100);

		playText.setPosition(200, 200);
		scoreText.setPosition(200, 300);
		aboutText.setPosition(200, 400);
		exitText.setPosition(200, 500);

		//set menubackground
		RectangleShape background;
		background.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		Texture mainTexture;
		mainTexture.loadFromFile("bgMenu.jpg");
		background.setTexture(&mainTexture);

		//set about
		RectangleShape htp;
		htp.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		Texture aboutTexture;
		aboutTexture.loadFromFile("htp.jpg");
		htp.setTexture(&aboutTexture);

		//set return
		RectangleShape re;
		re.setSize(Vector2f(100.f,100.f));
		re.setPosition(25,25);
		Texture reTexture;
		reTexture.loadFromFile("return.png");
		re.setTexture(&reTexture);

		Clock clock;
		float deltaTime = 0;

		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			if (playText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{
				playText.setFillColor(Color::Blue);
			}
			else if (scoreText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{
				scoreText.setFillColor(Color::Blue);
			}
			else if (aboutText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{
				aboutText.setFillColor(Color::Blue);
			}
			else if (exitText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
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
				if (playText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					while (window.isOpen())
					{
						deltaTime = clock.restart().asSeconds();
						Event ev;
						while (window.pollEvent(ev))
						{
							if (ev.type == Event::Closed)
								window.close();
							else if (ev.type == Event::KeyPressed)
							{
								if (ev.key.code == Keyboard::Escape)
								{
									window.close();
								}
							}
						}
						game.update(deltaTime);
						
						window.clear();
						
						game.render();
						
						window.display();

					}
				}
				else if (scoreText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{

				}
				else if (aboutText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					while (window.isOpen())
					{
						Event aevent;
						while (window.pollEvent(aevent))
						{
							if (aevent.type == Event::Closed)
							{
								window.close();
							}
							if (aevent.type == Event::KeyPressed)
							{
								if (aevent.key.code == Keyboard::Escape)
								{
									window.close();
								}
							}
							/*if (re.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
							{
								push all window.isOpen in here
							}*/
						}
						window.clear();

						window.draw(htp);

						window.draw(re);

						window.display();
					}
				}
				else if (exitText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					window.close();
				}
			}

			window.clear();

			window.draw(background);

			window.draw(playText);

			window.draw(scoreText);

			window.draw(aboutText);

			window.draw(exitText);

			window.display();
		}
		return 0;
}