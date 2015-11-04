#include "stdafx.h"
#include "Goblin.h"


Goblin::Goblin(int multiplier) : Monster()
{
	// Hard coded, can be changed later..
	setMonsterName("Goblin");
	setStats(3 * multiplier, 4 * multiplier, 2 * multiplier, 2 * multiplier, 2 * multiplier);
	setMonsterDescription("An evil Goblin");
}

Goblin::~Goblin()
{
}
