#include <SFML/Graphics.hpp>
#include <iostream>
#include "windows.h"
#include "people.h"
#include <vector>

bool getData(int x, int y);

int main()
{
		sf::Event evnt;
		sf::Image image;
		sf::Sprite sprite;
		sprite.setScale(0.5, 0.5);
		sprite.setPosition(100, 100);
		sf::Texture texture;
		image.loadFromFile("uk.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		std::vector<people> population;

		for (int i = 0; i < image.getSize().x; i++)
		{
			for (int j = 0; j < image.getSize().y; j++)
			{
				if (image.getPixel(i, j).b != 0)
				{
					population.push_back(people(i, j));
				}
			}
		}

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Map");
	while (window.isOpen())
	{

		while (window.pollEvent(evnt))
		{
			if (sf::Event::EventType::Closed)
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		window.clear();

		texture.loadFromImage(image);
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();


		for (int i = 0; i < image.getSize().x; i++)			//Basically checks each pixel too
		{													//see if its blue and then changes it
			for (int j = 0; j < image.getSize().y; j++)		//to green. Ideally we'll have a function
			{												//that checks the data of the pixel and
				if (image.getPixel(i, j).b != 0				//corresponding vector element to test
					&& i != image.getSize().x)				//if they'll get infected rather than	
				{											//if the pixel is blue.
					image.setPixel(i, j, sf::Color::Green);
					texture.loadFromImage(image);
					sprite.setTexture(texture);
					window.draw(sprite);
					window.display();
				}

				/*

				Some code I was testing to see how infected pixels could spread to surrounding ones.

				Issue arose when checking for a pixel that was outside the range of the image causing
				the program to crash.


				if (image.getPixel(i, j).g > 200 && image.getPixel(i - 1, j).b != 0
					&& i != 0)
				{
					image.setPixel(i - 1, j, sf::Color::Green);

					texture.loadFromImage(image);
					sprite.setTexture(texture);
					window.draw(sprite);
					window.display();
				}

				if (image.getPixel(i, j).g > 220 && image.getPixel(i, j+1).b != 0
					&& i != image.getSize().y)
				{
					image.setPixel(i , j+1, sf::Color::Green);

					texture.loadFromImage(image);
					sprite.setTexture(texture);
					window.draw(sprite);
					window.display();
				}
				*/
			}

		}


		return 0;
	}
	}
