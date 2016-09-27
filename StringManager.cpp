#include "StringManager.h"
#include "FontManager.h"
#include <SFML\System\String.hpp>

using sf::String;

StringManager::StringManager()
{
	snakeFontManager = new FontManager;


	String stringTitle = "Snake";
	String stringtextExit = "Exit";
	String stringtextStart = "Start game";

	titleInMenu.setString(stringTitle);
	titleInMenu.setFont(snakeFontManager->gameFont);
	titleInMenu.setPosition(300, 50);

	textExit.setString(stringtextExit);
	textExit.setFont(snakeFontManager->gameFont);
	textExit.setPosition(300, 200);

	textStart.setString(stringtextStart);
	textStart.setFont(snakeFontManager->gameFont);
	textStart.setPosition(300, 100);

	

}

StringManager::~StringManager()
{
	snakeFontManager->~FontManager();
}
