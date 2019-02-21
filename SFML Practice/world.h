#pragma once
#include <stdio.h>
#include <vector>
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "pixel.h"

class world
{
public:
	world(int width, int height, std::string backgroundFilePath, int columns, int rows, sf::RenderWindow *window);
	~world();
	void init(std::string);

	int size;

	int infectedCount;
	int totalPeopleCount;


	void Draw();
	void chooseStartLocation();
	void Update();

	int width, height;
private:
	sf::RenderWindow *window;
	std::string backgroundFilePath;
	sf::Image backImage;
	
	int columns, rows;
	std::vector<std::vector<pixel>> pixels;
	void spread(int,sf::Vector2f);

	sf::Color landColour, waterColour;

	bool validSpread(int, int);
	
};

