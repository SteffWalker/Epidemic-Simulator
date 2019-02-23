#include "people.h"
#include "SFML/Graphics.hpp"


people::people(int x, int y)
{
	xPos = x;
	yPos = y;
}


people::~people()
{
}

void people::setInfected(sf::Image image)
{
	infected = true;
	image.setPixel(xPos, yPos, sf::Color::Red);
}

bool people::getInfected()
{
	return infected;
}
