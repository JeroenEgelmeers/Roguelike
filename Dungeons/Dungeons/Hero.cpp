#include "stdafx.h"
#include "Hero.h"

Hero::Hero() {
	// Set stats
	level		= 1;
	health		= 10;
	xp			= 0;
	attack		= 3;
	strength	= 3;
	defence		= 3;
}
Hero::~Hero() {}

void Hero::increaseLevel(int value)
{
	level += value;
}

void Hero::removeHealth(int value)
{
	health -= value;
}

void Hero::addHealth(int value) {
	health += value;
}

void Hero::increaseXp(int value)
{
	xp += value;
}

void Hero::increaseAttack(int value = 1)
{
	attack += value;
}

void Hero::increaseStrenght(int value = 1)
{
	strength += value;
}

void Hero::increaseDefence(int value = 1)
{
	defence += value;
}

void Hero::getHeroStats()
{
	cout << "[[ Your currently level is: " << Hero::getLevel() << " and you've got " << Hero::getXp() << " experience! ]] \n"
		 << "[[ Health: " << Hero::getHealth() << " HP || "	 
		 << "Attack: " << Hero::getAttack() << " || "		 
		 << "Strength: " << Hero::getStrength() << " || "	 
		 << "Defence: " << Hero::getDefence() << " ]] \n";
}

bool Hero::setUserName(string inputUserName) {
	if (userName == "") {
		userName = inputUserName;
		return true;
	}
	else {
		// UserName is already set!
		return false;
	}
}

string Hero::getRoomDescription()
{
	return curroom->GetDescription();
}

void Hero::setRoom(Room* room)
{
	curroom = room;
	/*cout << "Coordinates are: \n";
	cout << curroom->GetX();
	cout << " ";
	cout << curroom->GetY();*/
}

bool Hero::moveHero(int direction)
{
	return curroom->MovePlayer(direction);
}


