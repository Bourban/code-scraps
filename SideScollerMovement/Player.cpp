#include "Player.h"
#include <iostream>


Player::Player(sf::Texture &texture)
{
	this->setTexture(texture);
	this->setPosition(400, 400);
	this->isOnGround = false;
	this->isFacingLeft = false;
	this->setOrigin(this->spriteWidth / 2, this->spriteHeight / 2);
	this->bottom.height = 2;
	this->bottom.width = (spriteWidth * 0.3) /2;
}


Player::~Player()
{
}

void Player::update(sf::Time &time)
{
	this->delta = &time;

	this->onGroundCheck();
	
	this->move(0, -(deltaHeight * delta->asSeconds()));
	
	this->boundsCheck();
	this->handleSpriteDirection();
	this->handleBoxes();

	std::cout << isOnGround << std::endl;
	
}

void Player::onGroundCheck()
{
	if (!isOnGround) {
		if (this->deltaHeight > -500)
		{
			this->deltaHeight -= 1000 * delta->asSeconds();
		};
	}
	else {
		this->deltaHeight = 0;
	}

}

void Player::boundsCheck()
{
	if (this->getPosition().y > 600)
	{
		this->setPosition(this->getPosition().x, 600);
		this->isOnGround = true;
	};

	if (this->getPosition().x < 100)
	{
		this->setPosition(100, this->getPosition().y);
	};

	if (this->getPosition().x > 1000)
	{
		this->setPosition(1000, this->getPosition().y);
	};
}

void Player::handleSpriteDirection()
{
	if (this->isFacingLeft)
	{
		this->setScale(-0.3, 0.3);
	}
	else
	{
		this->setScale(0.3, 0.3);
	}

}

sf::FloatRect Player::getBoundingBox() const
{
	return this->bottom;
}

void Player::moveLeft()
{
	this->move(-220 * delta->asSeconds(), 0);
	this->isFacingLeft = true;
}

void Player::moveRight()
{
	this->move(220 * delta->asSeconds(), 0); 
	this->isFacingLeft = false;
}

void Player::jump()
{
	if (this->isOnGround) {
		this->deltaHeight = 550;
		this->isOnGround = false;
	}
}

void Player::handleBoxes()
{
	this->bottom.left = this->getPosition().x;
	this->bottom.top = this->getPosition().y + (this->spriteHeight * 0.3) / 2;
}

void Player::checkTouchingGround(sf::FloatRect & ground)
{
	if (bottom.intersects(ground) && this->deltaHeight <= 0) {
		//this->setPosition(this->getPosition().x, ground.top - ((spriteWidth * 0.3) / 2) - 1);
		this->isOnGround = true;
		
	}

}
