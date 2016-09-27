#include "Food.h"
#include "TextureManager.h"

Food::Food()
{
	texture = new TextureManager("apple.jpg", 10, 10);
	boxFood.setPosition(300, 400);
	boxFood.setSize(sf::Vector2f(10, 10));
	boxFood.setTexture(& texture->textureForObject);
}

Food::~Food()
{

}
