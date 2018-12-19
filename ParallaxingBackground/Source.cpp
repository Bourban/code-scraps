#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

int main() {

	sf::RenderWindow window(sf::VideoMode(1024, 780), "Parallaxing Background Example");
	sf::View view;

	int numElements = 10;

	sf::Clock clock;
	sf::Time delta;

	std::vector<sf::Sprite> sprites;
	std::vector<float> distances;

#pragma region Sprite Setup
	sf::Texture bg01;
	if (!bg01.loadFromFile("bgs/_01_ground.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg02;
	if (!bg02.loadFromFile("bgs/_02_trees and bushes.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg03;
	if (!bg03.loadFromFile("bgs/_03_distant_trees.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg04;
	if (!bg04.loadFromFile("bgs/_04_bushes.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg05;
	if (!bg05.loadFromFile("bgs/_05_hill1.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg06;
	if (!bg06.loadFromFile("bgs/_06_hill2.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg07;
	if (!bg07.loadFromFile("bgs/_07_huge_clouds.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg08;
	if (!bg08.loadFromFile("bgs/_08_clouds.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg09;
	if (!bg09.loadFromFile("bgs/_09_distant_clouds1.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg10;
	if (!bg10.loadFromFile("bgs/_10_distant_clouds.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sf::Texture bg11;
	if (!bg11.loadFromFile("bgs/_11_background.png")) {
		std::cout << "Faield to load dis nigga";
	}

	sprites.push_back(sf::Sprite(bg11));
	sprites.push_back(sf::Sprite(bg10));
	sprites.push_back(sf::Sprite(bg09));
	sprites.push_back(sf::Sprite(bg08));
	sprites.push_back(sf::Sprite(bg07));
	sprites.push_back(sf::Sprite(bg06));
	sprites.push_back(sf::Sprite(bg05));
	sprites.push_back(sf::Sprite(bg04));
	sprites.push_back(sf::Sprite(bg03));
	sprites.push_back(sf::Sprite(bg02));
	sprites.push_back(sf::Sprite(bg01));

	distances.push_back(0);
	distances.push_back(0);
	distances.push_back(0.1f);
	distances.push_back(0.2f);
	distances.push_back(0.3f);
	distances.push_back(0.4f);
	distances.push_back(0.6f);
	distances.push_back(0.8f);
	distances.push_back(0.9f);
	distances.push_back(1);
	distances.push_back(1);


#pragma endregion

	view.zoom(1);
	view.move(600, 400);
	window.setView(view);

	for (int i = 0; i <= numElements; i++)
	{
		//sprites[i].setScale(0.5f, 0.5f);
		sprites[i].setPosition(0, 0);
	}
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		delta = clock.restart();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			for (int i = 0; i <= numElements; i++)
			{
				sprites[i].move((100 * delta.asSeconds()) * distances[i], 0);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			for (int i = 0; i <= numElements; i++)
			{
				sprites[i].move((-100 * delta.asSeconds()) * distances[i], 0);
			}
		}

		window.clear();
		for (int i = 0; i <= numElements; i++) 
		{
			window.draw(sprites[i]);
		}
		window.display();
	}


	return 0;
}
