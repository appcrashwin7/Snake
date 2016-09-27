#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\System\Time.hpp>
#include "Game.h"
#include <cstdlib>
#include <ctime>

using sf::Clock;
using sf::Time;
using sf::Keyboard;

int main()
{
	Game snakeGame;

	srand((unsigned int)time(NULL));
	
	Clock clock;
	Time time;
	
	while (snakeGame.GameWindow.isOpen())
	{
		sf::Event event;
		while (snakeGame.GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				snakeGame.GameWindow.close();
		}

		if (snakeGame.MenuManager() == 0)
		{
			snakeGame.GameWindow.close();
			return EXIT_SUCCESS;
		}

			if (Keyboard::isKeyPressed(Keyboard::Up) && snakeGame.direction_snake != 3)
			{
				snakeGame.direction_snake = (Game::Direction)1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Left) && snakeGame.direction_snake != 4)
			{
				snakeGame.direction_snake = (Game::Direction)2;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) && snakeGame.direction_snake != 1)
			{
				snakeGame.direction_snake = (Game::Direction)3;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) && snakeGame.direction_snake != 2)
			{
				snakeGame.direction_snake = (Game::Direction)4;
			}

		time = clock.getElapsedTime();
		if (time.asSeconds() >= snakeGame.game_speed)
		{
			snakeGame.actualize_position_snake();
			clock.restart();
		}

		snakeGame.GameWindow.clear();
		if (snakeGame.gameover() == true)
		{
			return EXIT_SUCCESS;
		}
		snakeGame.RenderMenu();
		snakeGame.RenderMap();
		snakeGame.DrawSnake();
		snakeGame.GameWindow.display();

		if (snakeGame.GameManager() == 1)
		{
			snakeGame.game_over = true;
		}
	}
	return 0;
}