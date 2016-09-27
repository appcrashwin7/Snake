#pragma once
#include <vector>
#include <SFML\Graphics\RectangleShape.hpp>


using std::vector;
using sf::RectangleShape;

class Snake
{

	class TextureManager *texture_for_snake;
public:
	RectangleShape snakeHead;

	vector <RectangleShape> body;

	Snake();
	void addFragmentToBody();
	void moveFragmentBody();
	bool checkingCollisionsHead_with_Body();

};