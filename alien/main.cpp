#include "Game.h"
#include "Menu.h"

int main()
{
	//make a menu
	RenderWindow MENU(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Main Menu", Style::Fullscreen);
	Menu menu(MENU.getSize().x, MENU.getSize().y);

	//set background
	RectangleShape background;
	background.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture mainTexture;
	mainTexture.loadFromFile("bgMenu.jpg");
	background.setTexture(&mainTexture);

	//photo to the game
	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture back_texture;
	back_texture.loadFromFile("123.jpg");
	Pbackground.setTexture(&back_texture);

	//photo to the score
	RectangleShape Sbackground;
	Sbackground.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture score_texture;
	score_texture.loadFromFile("123.jpg");
	Sbackground.setTexture(&score_texture);

	//photo to the about
	RectangleShape Abackground;
	Abackground.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture about_texture;
	about_texture.loadFromFile("123.jpg");
	Abackground.setTexture(&about_texture);

	Clock clock;
	float deltaTime = 0;

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type==Event::Closed)
			{
				MENU.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					menu.moveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					menu.moveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Score(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SCORE", Style::Fullscreen);
					RenderWindow Exit(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "EXIT", Style::Fullscreen);
					RenderWindow About(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ABOUT", Style::Fullscreen);
					RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Fullscreen);
					window.setVerticalSyncEnabled(true);
					srand(time(0));
					Game game(&window);

					int x = menu.MenuPressed();
					if (x == 0)
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

							Score.close();

							About.close();

							Exit.close();

							MENU.clear();

							game.update(deltaTime);

							window.clear();

							game.render();

							window.display();

						}
					}
					if (x == 1)
					{
						while (Score.isOpen())
						{
							Event aevent;
							while (Score.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Score.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Score.close();
									}
								}
							}
							window.close();

							About.close();

							Exit.close();

							Score.clear();

							Score.draw(Sbackground);

							Score.display();
						}
					}
					if (x == 2)
					{
						while (About.isOpen())
						{
							Event aevent;
							while (About.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									About.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										About.close();
									}
								}
							}
							window.close();

							Score.close();

							Exit.close();

							About.clear();

							About.draw(Abackground);

							About.display();
						}
					}
					if (x == 3)
						MENU.close();
						break;
				}
			}
		}

		MENU.clear();

		MENU.draw(background);

		menu.draw(MENU);

		MENU.display();
	}
	return 0;
}