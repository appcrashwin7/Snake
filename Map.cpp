#include "Map.h"
#include "TextureManager.h"

Map::Map()
{
	mapTexture = new TextureManager("grass_pixel.jpg",400,400);
	squareMap.setPosition(200, 100);
	squareMap.setSize(sf::Vector2f(400, 400));
	squareMap.setTexture(& mapTexture->textureForObject);
}

Map::~Map()
{

}
