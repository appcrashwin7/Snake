#pragma once
#include <SFML\Graphics.hpp>

using sf::Mouse;
using sf::RenderWindow;
using sf::Font;
using sf::Text;

class Game
{
	class Menu * GameMenu;
	class Map * GameMap;
	class Snake * ssnake;
	class AudioManager *GameAudioManager;
	class Food *snakeFood;
	class Select_Lvl *Menu_Sel_Lvl;
public:
	RenderWindow GameWindow;
	Font font;
	bool game_over;
	enum Direction
	{
		Up = 1,
		Left,
		Down,
		Right
	};
	enum State
	{
		is_game = 1,
		is_menu,
		is_select_lvl
	};

	Direction direction_snake;
	float game_speed;
private:
	State GameState;
	int score;
	int scoreMultp;
	Text gameScore;
	int isSnakeCollisions();
	void changeScore();
	Mouse snakeMouse;
	sf::Vector2i mousePosition;
public:
	bool gameover();
	int MenuManager();
	int GameManager();
	void SelectLvlManager();
	void RenderMenu();
	void RenderMap();
	void DrawSnake();
	void changePositionFood();
	void actualize_position_snake();
	void grow_snake();
	void restart_game();

	Game();
	~Game();
};