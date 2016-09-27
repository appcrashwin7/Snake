#include "TextureManager.h"

TextureManager::TextureManager(String nameOfTexture,int height,int width)
{
	textureForObject.loadFromFile(nameOfTexture, sf::IntRect(0, 0, width, height));
}

TextureManager::TextureManager(String nameofTexture, int height, int width, int begin_x, int begin_y)
{
	textureForObject.loadFromFile(nameofTexture, sf::IntRect(begin_x, begin_y, width, height));
}
