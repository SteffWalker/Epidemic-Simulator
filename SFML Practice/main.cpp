#include <SFML/Graphics.hpp>
#include "world.h";
#include <thread>


const int screenWidth = 1200;
const int screenHeight = 700;

//const int size = 1;

//const int columns = screenWidth / size;
//const int rows = screenHeight / size;

std::string file = "UK.png";
sf::Image temp;

struct Param {
	sf::RenderWindow* window;
		world* world;

};

void renderingThread(Param p) {
	while (p.window->isOpen()) {
		p.window->clear();
		

		p.world->Draw();
		//p.world->Update();

		p.window->display();
	}

}





int main()
{
	temp.loadFromFile(file);
	int sizeX = temp.getSize().x;
	int sizeY = temp.getSize().y;
	sf::RenderWindow window(sf::VideoMode(sizeX , sizeY), "Outbreak Sim");

	window.setActive(false);
	world world(sizeX, sizeY, file, sizeX, sizeY, &window);

	world.chooseStartLocation();
	Param param{ &window, &world };
	sf::Thread t1(&renderingThread, param);
	t1.launch();





	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
				{
					window.close();
				}
			}
		}

		world.Update();
		//window.clear();
		//std::thread t1(&world::Draw, world);
		//std::thread t2(&world::Update, world);
		//window.display();
	}

	return 0;
}