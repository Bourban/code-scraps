#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>



int main()
{
	sf::RenderWindow window(sf::VideoMode(1240, 800), "SFML works!");

	window.setFramerateLimit(18.0f);

	sf::Texture texture;

	if (!texture.loadFromFile("Resources/spritesheet_idle.png")) {
		std::cout << "Texture failed to load!";
	}

	//holds all the spites
	std::vector<sf::Sprite> sprites;

	//3 rows of 4 frames, 1205 is the height of each frame and 800 is the width, adjust numbers appropriatley if reused
	//TODO: use variables instead
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			sprites.push_back(sf::Sprite(texture, sf::IntRect(1205 * j, 800 * i, 1205, 800)));
		}
	}

	//counter variable for the frames
	int frameIndex = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		frameIndex++;
		frameIndex = frameIndex % sprites.size();


		window.clear(sf::Color::Blue);
		window.draw(sprites[frameIndex]);
		window.display();

	}
	return 0;
}

