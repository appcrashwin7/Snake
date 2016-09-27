#pragma once
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

using sf::RectangleShape;
using sf::Text;

class Select_Lvl
{
	RectangleShape Box_Easy;
	RectangleShape Box_Normal;
	RectangleShape Box_Hard;

	Text Text_Easy;
	Text Text_Normal;
	Text Text_Hard;
public:
	Select_Lvl(sf::Font & font);
	void DrawSelectLvl(sf::RenderWindow & Window);
};