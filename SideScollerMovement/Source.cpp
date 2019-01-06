#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Sgt Spookington");
	window.setFramerateLimit(60);

	sf::Texture jabroni;

	sf::FloatRect pls = sf::FloatRect(0, 600, 1280, 5);

	Player player = Player(jabroni);
	sf::Clock clock;
	sf::Time elapsed;

	jabroni.loadFromFile("idle_000.png");
	//player.setTexture(jabroni);
	player.setTextureRect(sf::IntRect(0, 0, 650, 800));

	player.setScale(0.3f, 0.3f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			player.jump();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

			player.moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			player.moveRight();
		}

		player.checkTouchingGround(pls);

		elapsed = clock.restart();
		player.update(elapsed);

		window.clear(sf::Color::Cyan);
		window.draw(player);
		window.display();
	}


	return 0;
}