#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>

class Player :
	public sf::Sprite
{
public:
	Player(sf::Texture &texture);
	~Player();

	void update(sf::Time &time);

	void onGroundCheck();
	//makes sure the player stays within the bounds of the screen
	void boundsCheck();
	//makes sure the sprite is pointing the right way
	void handleSpriteDirection();

	sf::FloatRect getBoundingBox() const;
	void moveLeft();
	void moveRight();
	void jump();
	void handleBoxes();

	void checkTouchingGround(sf::FloatRect &ground);

private:
	sf::Time* delta;
	bool isOnGround;
	bool isFacingLeft;

	sf::IntRect boundingBox;
	sf::FloatRect bottom;
	float deltaHeight;

	const int spriteHeight = 800;
	const int spriteWidth = 650;
};

