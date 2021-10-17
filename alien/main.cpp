#include "Game.h"

int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	srand(time(0));
	Game game(&window);

	Clock clock;
	float deltaTime = 0;

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

	return 0;
}