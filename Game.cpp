#include "Game.h"
#include "Menu.h"
#include "StringManager.h"
#include "Map.h"
#include "Food.h"
#include "Snake.h"
#include "AudioManager.h"
#include "Select_Lvl.h"
#include <ctime>
#include <cstdlib>
#include <sstream>

using sf::String;

int Game::isSnakeCollisions()
{
	sf::Vector2f snakeHeadPosition = ssnake->snakeHead.getPosition();
	sf::Vector2f FoodPosition = snakeFood->boxFood.getPosition();
	sf::Vector2f MapFramePosition = GameMap->squareMap.getPosition();

	if (snakeHeadPosition.x > FoodPosition.x + 10 || snakeHeadPosition.x + 10 < FoodPosition.x || snakeHeadPosition.y > FoodPosition.y + 10 || snakeHeadPosition.y + 10 < FoodPosition.y)
	{}
	else
	{
		return 3;
	}
	if (MapFramePosition.x <= snakeHeadPosition.x || MapFramePosition.x > snakeHeadPosition.x && snakeHeadPosition.y < MapFramePosition.y && snakeHeadPosition.y + 10 < MapFramePosition.y
		|| snakeHeadPosition.y > MapFramePosition.y + 400)
	{}
	else
	{
		return 1;
	}
	if (MapFramePosition.x + 400 > snakeHeadPosition.x || MapFramePosition.x + 400 < snakeHeadPosition.x + 10 && snakeHeadPosition.y < MapFramePosition.y && snakeHeadPosition.y + 10 < MapFramePosition.y
		|| snakeHeadPosition.y > MapFramePosition.y + 400)
	{}
	else
	{
		return 1;
	}
	if (snakeHeadPosition.y + 10 <= MapFramePosition.y || snakeHeadPosition.y + 10 <= MapFramePosition.y && snakeHeadPosition.x < MapFramePosition.x && snakeHeadPosition.x + 10 < MapFramePosition.x + 400)
	{
		return 1;
	}
	if (snakeHeadPosition.y >= MapFramePosition.y + 400 || snakeHeadPosition.y >= MapFramePosition.y + 400 && snakeHeadPosition.x < MapFramePosition.x && snakeHeadPosition.x + 10
		<= MapFramePosition.x + 400)
	{
		return 1;
	}
	if (ssnake->checkingCollisionsHead_with_Body() == true)
	{
		return 2;
	}
	
		return 0;
}

void Game::changeScore()
{
	std::ostringstream ostr;
	ostr << score;

	String string = ostr.str();
	gameScore.setString(string);
}

int Game::MenuManager()
{
	
	if (GameState == is_menu)
	{
		mousePosition = snakeMouse.getPosition(GameWindow);

		if (mousePosition.x >= 300 && mousePosition.x <= 500
			&& mousePosition.y >= 100 && mousePosition.y <= 150)
		{
			if (snakeMouse.isButtonPressed(sf::Mouse::Left) == true)
			{
				mousePosition.x = 0;
				mousePosition.y = 0;
				Menu_Sel_Lvl->DrawSelectLvl(GameWindow);
				SelectLvlManager();
				GameState = is_game;
				return 1;
			}
		}
		else if (mousePosition.x >= 300 && mousePosition.x <= 500
			&& mousePosition.y >= 200 && mousePosition.y <= 250)
		{
			if (snakeMouse.isButtonPressed(sf::Mouse::Left) == true)
			{
				return 0;
			}
		}
		else
		{
			return 2;
		}
	}
	return 2;
}

int Game::GameManager()
{
	if (GameState == is_game)
	{	
		if (game_over == true)
		{
		return 0;
		}

		int eventCollisions = isSnakeCollisions();

		if (eventCollisions == 3)
		{
			grow_snake();
			changePositionFood();
			score += scoreMultp;
			changeScore();
			GameAudioManager->play_audio();
		}
		else if (eventCollisions == 1)
		{
			return 1;
		}
		else if (eventCollisions == 2)
		{
			return 1;
		}
	return 0;
	}
	return 0;
}

void Game::SelectLvlManager()
{
	mousePosition.x = 200;
	mousePosition.y = 200;
	snakeMouse.setPosition(mousePosition);
	while (true)
	{
		mousePosition = snakeMouse.getPosition(GameWindow);
		if (mousePosition.x >= 300 && mousePosition.x <= 500
			&& mousePosition.y >= 100 && mousePosition.y <= 150)
		{
			if (snakeMouse.isButtonPressed(sf::Mouse::Left) == true)
			{
				game_speed = 0.5f;
				scoreMultp = 10;
				return;
			}
		}
		 if (mousePosition.x >= 300 && mousePosition.x <= 500
			&& mousePosition.y >= 200 && mousePosition.y <= 250)
		{
			if (snakeMouse.isButtonPressed(sf::Mouse::Left) == true)
			{
				game_speed = 0.25f;
				scoreMultp = 20;
				return;
			}
		}
		 if (mousePosition.x >= 300 && mousePosition.x <= 500
			&& mousePosition.y >= 300 && mousePosition.y <= 350)
		{
			if (snakeMouse.isButtonPressed(sf::Mouse::Left) == true)
			{
				game_speed = 0.10f;
				scoreMultp = 30;
				return;
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			game_speed = 0.25f;
			scoreMultp = 20;
			return;
		}
	}
	return;
}

void Game::RenderMenu()
{
	if (GameState == is_menu )
	{
		GameWindow.draw(GameMenu->BoxStart);
		GameWindow.draw(GameMenu->BoxExit);
		GameWindow.draw(GameMenu->snakeMenuStringManager->titleInMenu);
		GameWindow.draw(GameMenu->snakeMenuStringManager->textStart);
		GameWindow.draw(GameMenu->snakeMenuStringManager->textExit);
	}
}

void Game::changePositionFood()
{
	int x = 200 + (int)(rand() / (RAND_MAX + 1.0) * 390);
	int y = 100 + (int)(rand() / (RAND_MAX + 1.0) * 390);  /* losowanie liczby z zakresu <100,390> */

	float x_f = (float)x;
	float y_f = (float)y;

	snakeFood->boxFood.setPosition(x_f, y_f);
}

void Game::RenderMap()
{
	if (GameState == is_game)
	{
		GameWindow.draw(GameMap->squareMap);
		GameWindow.draw(snakeFood->boxFood);
		GameWindow.draw(gameScore);
	}
}

void Game::DrawSnake()
{
	if (GameState == is_game)
	{
		GameWindow.draw(ssnake->snakeHead);
		for (std::size_t a = 0; a < ssnake->body.size(); a++)
		{
			GameWindow.draw(ssnake->body[a]);
		}
	}
}

void Game::actualize_position_snake()
{
	if (GameState == is_game)
	{
		ssnake->moveFragmentBody();

		sf::Vector2f position_snake = ssnake->snakeHead.getPosition();
		if (direction_snake == Up)
		{
			position_snake.y = position_snake.y - 10;
		}
		else if(direction_snake == Left)
		{
			position_snake.x = position_snake.x - 10;
		}
		else if (direction_snake == Down)
		{
			position_snake.y = position_snake.y + 10;
		}
		else if(direction_snake == Right)
		{
			position_snake.x = position_snake.x + 10;
		}
		ssnake->snakeHead.setPosition(position_snake);
	}
}

void Game::grow_snake()
{
	ssnake->addFragmentToBody();
}

void Game::restart_game()
{
	game_over = false;
	ssnake->snakeHead.setPosition(400, 400);
	direction_snake = Up;
	score = 0;

	for (size_t i = ssnake->body.size(); i > 3; --i)
	{
		ssnake->body.pop_back();
	}
}

bool Game::gameover()
{
	if (game_over == false)
	{
		return false;
	}
	Text text;
	text.setFont(font);
	text.setString("Game Over press R to restart or Esc to exit");
	text.setPosition(100,300);
	GameWindow.draw(text);
	GameWindow.display();
	while (true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) == true)
		{
			restart_game();
			return false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == true)
		{
			return true;
		}
	}
}

Game::Game()
{
	GameMenu = new Menu;
	GameMap = new Map;
	snakeFood = new Food;
	ssnake = new Snake;
	GameAudioManager = new AudioManager;
	Menu_Sel_Lvl = new Select_Lvl(font);
	
	GameState = is_menu;
	game_over = false;
	direction_snake = Up;
	score = 0;
	scoreMultp = 10;
	game_speed = 0.10f;

	GameWindow.create(sf::VideoMode(800, 600, 32),"Snake",sf::Style::Default);
	GameWindow.setFramerateLimit(60);
	
	font.loadFromFile("arial.ttf");
	gameScore.setPosition(10, 10);
	gameScore.setFont(font);
	gameScore.setCharacterSize(20);

	std::ostringstream ostr;
	ostr << score;

	String string = ostr.str();
	gameScore.setString(string);
}

Game::~Game()
{
	delete GameMap;
	delete GameMenu;
	delete ssnake;
	delete snakeFood;
	delete GameAudioManager;
}

