#pragma once
#include <SFML\Graphics\RectangleShape.hpp>

using sf::RectangleShape;

class Food
{

	class TextureManager *texture;

public:
	RectangleShape boxFood;

	Food();
	~Food();


};