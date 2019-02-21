#include "pixel.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

pixel::pixel(int column, int row, sf::Color color, int size, sf::RenderWindow *window) : column(column), row(row), cellColor(color), size(size), window(window)
{


	srand(time(NULL));
	//Setting its size and position Adding a Const value on so that the outline lines can be seen
	sf::Vector2f cellSize = sf::Vector2f(size, size);
	sf::Vector2f cellPos = sf::Vector2f(column*cellSize.x, row*cellSize.y);

	cellShape = sf::RectangleShape(cellSize);

	cellShape.setPosition(cellPos);
	cellShape.setFillColor(cellColor);
}


pixel::~pixel()
{
}

void pixel::draw() {



	window->draw(cellShape);
}

void pixel::setColour(sf::Color color) {
	cellShape.setFillColor(color);

}

void pixel::setPos(int x, int y) {
	cellShape.setPosition(sf::Vector2f(x, y));

}

sf::Vector2f pixel::getPos() {
	return cellShape.getPosition();
}

sf::Color pixel::getColour() {
	return cellShape.getFillColor();
}