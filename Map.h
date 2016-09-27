#pragma once
#include <SFML\Graphics\RectangleShape.hpp>

using sf::RectangleShape;

class Map
{
	class TextureManager *mapTexture;

public:
	RectangleShape squareMap;

	Map();
	~Map();
};