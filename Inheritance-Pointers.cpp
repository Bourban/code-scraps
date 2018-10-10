#include <iostream>

//file includes a base weapon class with virual functions, derived class(es) and a player calls with a pointer to a base weapon
//that allows to change the player's weapon type on the fly, without needing to include all the dirrernt weapon types in the 
//player class itself


class Weapon {
public:
	virtual void attack() {
		//Make this print "You don't have a weapon, you weapon" or something
		std::cout << "You Weapon!\n";
	}

};

class Axe : public Weapon {
public:
	void attack() {
		//Make this swing an axe etc.
		std::cout << "Can I axe you a question?\n";
	}

};

class Sword : public Weapon {
public:
	void attack() {
		//make this swing a sword etc.
		std::cout << "Stabby McStabFace \n";
	}

};

class Player {
public:
	Weapon *weapon;

	int damage;
};


int main() {

	Player player;

	player = Player();

	//player equips an axe
	player.weapon = new Axe();

	player.weapon->attack();

	//player equips a sword
	player.weapon = new Sword();

	player.weapon->attack();

	//the bad pause you're not meant to use because I was in a bit of a rush
	system("PAUSE");

	return 0;
}
