#pragma once
#include <SFML\Graphics\RectangleShape.hpp>

using sf::RectangleShape;

class SnakeBody
{
	RectangleShape bodyFragment;

public:
	SnakeBody();
	void GetPosition();
	void GetSize();
};