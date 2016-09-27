#pragma once
#include <SFML\Graphics\Text.hpp>

using sf::Text;

class StringManager
{
	class FontManager *snakeFontManager;

public:
	Text titleInMenu;

	Text textExit;

	Text textStart;

	StringManager();
	~StringManager();

};