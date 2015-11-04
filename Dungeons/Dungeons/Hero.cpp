#include "stdafx.h"
#include "Hero.h"

Hero::Hero() {
	// Set stats
	level		= 3;
	health		= 10;
	maxHealth	= 10;
	xp			= 0;
	attack		= 2;
	strength	= 2;
	defence		= 1;
	gameOver	= false;
	gameWon		= false;
}
Hero::~Hero() {}

void Hero::increaseLevel()
{
	level++;
	attack++;
	strength++;
	defence++;
	maxHealth = (maxHealth + 2);

	cout << "Congratulations! You just increased in combat! You're now level " << level;
}

bool Hero::healHero() {
	if (health < maxHealth) {
		health = maxHealth;
		return true;
	}
	else {
		return false;
	}
}

void Hero::removeHealth(int value)
{
	health -= value;
	if (health <= 0) {
		gameOver = true;
		cout << "\n\nGAME OVER!!! \n\n";
	}
}

void Hero::addHealth(int value) {
	health += value;
	if (maxHealth < health) { health = maxHealth; }
}

void Hero::increaseXp(int value)
{
	xp += value;

	if (level == 3 && xp > 30) {
		increaseLevel();
	}else if(level == 4 && xp > 90) {
		increaseLevel();
	}
	else if (level == 5 && xp > 200) {
		increaseLevel();
	}
	else if (level == 6 && xp > 400) {
		increaseLevel();
	}
	else if (level == 7 && xp > 800) {
		increaseLevel();
	}
	else if (level == 8 && xp > 1600) {
		increaseLevel();
	}
	else if (level == 9 && xp > 3200) {
		increaseLevel();
	}
	else if (level == 10 && xp > 64000) {
		increaseLevel();
	}
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

void Hero::getHeroStatsFight()
{
	cout << "[[ " << userName << " - level: " << getLevel() << " || "
		<< "Health: " << getHealth() << " HP || "
		<< "Attack: " << getAttack() << " || "
		<< "Strength: " << getStrength() << " || "
		<< "Defence: " << getDefence() << " ]] \n";
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
	if (curroom->getTrap()) {
		int trapRandom = rand() % curroom->getTrapKind() - getDefence();
		if (trapRandom <= 0) { trapRandom = 1; }
		removeHealth(trapRandom);
		curroom->removeTrap();

		cout << "A trap collapsed! You lost " << trapRandom << " HP! \n";
		return false;
	}
	else {
		bool success = curroom->MovePlayer(direction);
		if (curroom->special != 0)
			isonstairway = true;
		return success;
	}
}

bool Hero::gamePlaying()
{
	if (gameWon || gameOver) {
		return false;
	}
	else {
		return true;
	}
}

void Hero::setStairway(bool ios)
{
	isonstairway = ios;
}

