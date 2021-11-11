#include "Game.h"
#include "LeaderBoard.h"

int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Fullscreen);
		window.setVerticalSyncEnabled(true);
		srand(time(NULL));
		LeaderBoard ld;

		Font font;
		font.loadFromFile("PIXELED.ttf");

		Text playText("PLAY", font, 25);
		Text scoreText("SCORE", font, 25);
		Text aboutText("ABOUT", font, 25);
		Text exitText("EXIT", font, 25);

		playText.setPosition(910, 700);
		scoreText.setPosition(900, 775);
		aboutText.setPosition(898, 850);
		exitText.setPosition(915, 925);

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

		//set backToMenu
		RectangleShape btMenu;
		btMenu.setSize(Vector2f(350.f,100.f));
		btMenu.setPosition(770,600);
		Texture btMenuTexture;
		btMenuTexture.loadFromFile("backToMenu.png");
		btMenu.setTexture(&btMenuTexture);

		Text btmnText("Back to MENU", font, 25);
		btmnText.setPosition(810, 640);

		//set gameOver
		RectangleShape gameOver;
		gameOver.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		Texture gameOverTexture;
		gameOverTexture.loadFromFile("gameOver.jpg");
		gameOver.setTexture(&gameOverTexture);

		Text playerScore;
		playerScore.setFont(font);
		playerScore.setCharacterSize(25);
		playerScore.setPosition(815,520);

		//set scoreBoard
		RectangleShape scoreBoard;
		scoreBoard.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		Texture scoreBoardTexture;
		scoreBoardTexture.loadFromFile("scoreBoard.jpg");
		scoreBoard.setTexture(&scoreBoardTexture);

		//set return
		RectangleShape re;
		re.setSize(Vector2f(100.f, 100.f));
		re.setPosition(25, 25);
		Texture reTexture;
		reTexture.loadFromFile("return.png");
		re.setTexture(&reTexture);

		Clock clock;
		float deltaTime = 0;

		//Textbox
		Font tF;
		tF.loadFromFile("PIXELED.ttf");
		Textbox textbox1(50,Color::Black,true);
		textbox1.setFont(tF);
		textbox1.setPosition({ 705,570 });
		textbox1.setLimit(true, 10);

		float multiplier = 1;

		while (window.isOpen())
		{
		MENU:
			deltaTime = clock.restart().asSeconds() * multiplier;
			Event event;

			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				textbox1.setSelected(true);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				textbox1.setSelected(false);
			}

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();

				if (event.type == Event::TextEntered)
					textbox1.typedOn(event);

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
				//================================================================================================================================
				//=============================================================PLAY_TEXT=========================================================
				if (playText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && textbox1.getText() != "")
				{
					Game game(&window);
					float multiplier = 1;
					game.setName(textbox1.getText());
					while (window.isOpen())
					{
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
						//Trigger Game Over
						if (game.checkAlive() == 0)
						{
							float multiplier = 1;
							playerScore.setString("Score: " + to_string(game.getScore()));
							ld.addScore(game.getName(),game.getScore());
							ld.saveToFile("score.txt");
							game.reset();

							while(window.isOpen())
							{
								if (btmnText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
									{
										btmnText.setFillColor(Color(254, 206, 111, 255));
									}
								else
									{
										btmnText.setFillColor(Color::White);
									}
								//Game Over Scene
								if (btmnText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
								{
									goto MENU;
								}
								window.clear();

								window.draw(gameOver);

								window.draw(btMenu);

								window.draw(playerScore);

								window.draw(btmnText);

								window.display();								
								
							}
						}

						window.clear();

						game.render();

						window.display();

					}
				}
				//================================================================================================================================
				//=============================================================SCORE_TEXT=========================================================
				else if (scoreText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
				
					while (window.isOpen())
					{
						float multiplier = 1;
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
							if (re.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
							{
								goto MENU;
							}
						}

						ld.update();

						window.clear();

						window.draw(scoreBoard);

						window.draw(re);

						ld.render(window);

						window.display();
					}
				}
				//================================================================================================================================
				//=============================================================ABOUT_TEXT=========================================================
				else if (aboutText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					while (window.isOpen())
					{
						float multiplier = 1;
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
							if (re.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)&& Mouse::isButtonPressed(Mouse::Left))
							{
								goto MENU;
							}
						}
						window.clear();

						window.draw(htp);

						window.draw(re);

						window.display();
					}
				}
				//================================================================================================================================
				//=============================================================EXIT_TEXT=========================================================
				else if (exitText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					window.close();
				}
			}

			window.clear();

			window.draw(background);

			textbox1.drawTo(window);

			window.draw(playText);

			window.draw(scoreText);

			window.draw(aboutText);

			window.draw(exitText);

			window.display();
		}
		return 0;
}