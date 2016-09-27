#include "Select_Lvl.h"

Select_Lvl::Select_Lvl(sf::Font & font)
{
	Text_Easy.setFont( font);
	Text_Normal.setFont( font);
	Text_Hard.setFont( font);

	Text_Easy.setPosition(300, 100);
	Text_Normal.setPosition(300, 200);
	Text_Hard.setPosition(300, 300);

	Text_Easy.setString("Easy");
	Text_Normal.setString("Normal");
	Text_Hard.setString("Hard");

	Box_Easy.setPosition(300,100);
	Box_Normal.setPosition(300,200);
	Box_Hard.setPosition(300,300);

	Box_Easy.setSize(sf::Vector2f(200, 50));
	Box_Normal.setSize(sf::Vector2f(200,50));
	Box_Hard.setSize(sf::Vector2f(200,50));

	Box_Easy.setFillColor(sf::Color::Red);
	Box_Normal.setFillColor(sf::Color::Red);
	Box_Hard.setFillColor(sf::Color::Red);
}

void Select_Lvl::DrawSelectLvl(sf::RenderWindow & Window)
{
	Window.clear();
	Window.draw(Box_Easy);
	Window.draw(Box_Normal);
	Window.draw(Box_Hard);
	Window.draw(Text_Easy);
	Window.draw(Text_Normal);
	Window.draw(Text_Hard);
	Window.display();
}


