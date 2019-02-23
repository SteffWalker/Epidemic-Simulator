#pragma once
#include "SFML/Graphics.hpp"
class people
{
public:
	people(int x, int y);
	~people();
	void setInfected(sf::Image image);
	bool getInfected();
	int xPos;
	int yPos;

private:
	bool infected;
	int age;
};

