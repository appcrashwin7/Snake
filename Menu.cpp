#include "Menu.h"
#include "StringManager.h"

Menu::Menu()
{
	BoxStart.setPosition(sf::Vector2f(300, 100));
	BoxStart.setSize(sf::Vector2f(200, 50));
	BoxStart.setFillColor(sf::Color::Red);

	BoxExit.setPosition(sf::Vector2f(300, 200));
	BoxExit.setSize(sf::Vector2f(200, 50));
	BoxExit.setFillColor(sf::Color::Red);

	snakeMenuStringManager = new StringManager;
}

Menu::~Menu()
{
	snakeMenuStringManager->~StringManager();
}
