#pragma once
#include <SFML\Graphics\Font.hpp>

using sf::Font;

class FontManager
{
public:
	Font gameFont;

	FontManager();
	~FontManager();
};