#pragma once
#include <SFML\Graphics.hpp>

using sf::RectangleShape;

class Menu
{
public:
	RectangleShape BoxStart;
	RectangleShape BoxExit;

	class StringManager * snakeMenuStringManager;



	Menu();
	~Menu();
};