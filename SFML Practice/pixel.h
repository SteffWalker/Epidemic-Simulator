#include <stdio.h>
#include <vector>
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <algorithm>

class pixel
{
public:
	pixel(int column, int row, sf::Color colour, int size, sf::RenderWindow *window);
	~pixel();

	void draw();
	void setColour(sf::Color color);
	void setPos(int x, int y);
	sf::Vector2f getPos();
	sf::Color getColour();
	bool infected = false;

private:
	sf::RenderWindow *window;
	sf::RectangleShape cellShape;
	sf::Color cellColor;

	int column, row, size;
};

