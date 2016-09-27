#include "Snake.h"
#include "TextureManager.h"

using sf::Vector2f;

Snake::Snake()
{
	texture_for_snake = new TextureManager("snakebody.jpg", 10,10);
	snakeHead.setPosition(400, 400);
	snakeHead.setSize(Vector2f(10, 10));
	snakeHead.setTexture(& texture_for_snake->textureForObject);

	body.push_back(RectangleShape::RectangleShape(snakeHead));
	addFragmentToBody();
	addFragmentToBody();	
}

void Snake::addFragmentToBody()
{
	body.push_back(RectangleShape::RectangleShape(body.back()));
}

void Snake::moveFragmentBody()
{
	body[0].setPosition( snakeHead.getPosition());
	
	for (int i = body.size() - 1; i > 0; --i)
	{
		body[i].setPosition(body[i - 1].getPosition());
	}
}

bool Snake::checkingCollisionsHead_with_Body()
{
	Vector2f position_head = snakeHead.getPosition();
	Vector2f size_head = snakeHead.getSize();

	Vector2f size_of_element;
	Vector2f position_of_element;
	for (size_t i = body.size() - 1; i > 3; --i)
	{
		position_of_element = body[i].getPosition();
		size_of_element = body[i].getSize();

		if(position_head.x >= position_of_element.x + size_of_element.x || position_head.x + size_head.x <= position_of_element.x 
			|| position_head.y >= position_of_element.y + size_of_element.y || position_head.y + size_head.y <= position_of_element.y)
		{}
		else
		{
			return true;
		}
	}
	return false;
}
