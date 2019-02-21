#include "world.h"

//Sets the values in the header file to the passed through in the constructor
world::world(int width, int height, std::string backgroundFilePath, int columns, int rows, sf::RenderWindow *window) : width(width), height(height), backgroundFilePath(backgroundFilePath), columns(columns), rows(rows), window(window)
{
	init(backgroundFilePath);
	srand(time(NULL));

	landColour = sf::Color::Color(137, 175, 111);
	waterColour = sf::Color::Color(0,19,127);
}


world::~world()
{
}

void world::init(std::string backgroundFilePath) {

	//Size of cell
	size = (int)(width / columns);
	//std::cout << size;
	//const int col = columns;
	pixel temp = pixel(0, 0, sf::Color::Green, size, window);
	pixels.resize(rows, std::vector<pixel>(columns, temp));
	

	backImage.loadFromFile(backgroundFilePath);

	//std::cout << columns;
	sf::Color colour;
	//Create a 2D array of cells 
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < columns; y++) {
			
			colour= backImage.getPixel(y, x);


			if (colour == landColour) {
				totalPeopleCount += 1;
			
			}
			//colour = sf::Color::Red;
			pixels[x][y] = pixel(y, x, colour, size, window);

			
		}
		//std::cout << "X: "<<x << "\n";
	}


	std::cout << totalPeopleCount;
}

void world::Draw() {
	//Draw every single cell onto the screen
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < columns; y++) {
			pixels[x][y].draw();
			//std::cout << "Drawing :X:" << x << "  Y:" << y << "SHOULD BE AT: " << pixels[x][y].getPos().x <<"\n";
		}

	}

}

void world::chooseStartLocation() {
	int startX, startY;

	startX = rand() % width;
	startY = rand() % height;

	if (pixels[startY][startX].getColour() == landColour) {
		pixels[startY][startX].infected = true;
		std::cout << "Changed one at: " << startY << "  " << startX;
	}
	else {
		chooseStartLocation();
	}
}

void world::spread(int direction, sf::Vector2f pos) {
	switch (direction) {
	case 0: //UP
		if (validSpread(pos.x, pos.y - 1)) {
			pixels[pos.x][pos.y - 1].infected = true;
		}
		break;
	case 1: // DOWN
		if (validSpread(pos.x, pos.y + 1)) {
			pixels[pos.x][pos.y + 1].infected = true;
		}
		break;
	case 2: // left
		if (validSpread(pos.x - 1, pos.y)) {
			pixels[pos.x - 1][pos.y].infected = true;
		}
		break;
	case 3:
		if (validSpread(pos.x + 1, pos.y)) {
			pixels[pos.x + 1][pos.y].infected = true;
		}
		break;
	}

	infectedCount += 1;
	//std::cout << infectedCount << "\n";

}

bool world::validSpread(int x, int y)
{
	if (pixels[x][y].getColour() == landColour&& pixels[x][y].infected == 0) {
		return true;
	}


	return false;
}

void world::Update() {

	
	//LOOP OVER THE WHOLE 2D ARRAY
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			int direction = rand() % 4;
			if (pixels[j][i].infected == true) {
				pixels[j][i].setColour(sf::Color::Red);
				spread(direction, sf::Vector2f(j,i));


			}

		}

	}
}
