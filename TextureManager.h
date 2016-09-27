#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\String.hpp>

using sf::Texture;
using sf::String;

class TextureManager
{
public:
	Texture textureForObject;

	TextureManager(String nameOfTexture,int height,int width);

	TextureManager(String nameofTexture, int height, int width, int begin_x, int begin_y);

};