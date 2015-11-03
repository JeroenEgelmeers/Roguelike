#include "stdafx.h"
#include "Monster.h"


Monster::Monster() { }
Monster::~Monster() { }

void Monster::removeHealth(int value) {	health -= value; }
void Monster::addHealth(int value) { health += value; }

void Monster::getMonsterStats()
{
	cout << "[[ " << monsterName << " has level: " << getLevel() << " \n"
		<< "Health: " << getHealth() << " HP || "
		<< "Attack: " << getAttack() << " || "
		<< "Strength: " << getStrength() << " || "
		<< "Defence: " << getDefence() << " ]] \n";
}

void Monster::showMonsterHealth() { cout << monsterName << "has" << getHealth() << "health" << "\n"; }

void Monster::attackPlayer()
{
	// return what the monster hits on player.
}
