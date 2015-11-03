#include "stdafx.h"
#include "Goblin.h"


Goblin::Goblin() : Monster()
{
	// Hard coded, can be changed later..
	setMonsterName("Goblin");
	setStats(3, 4, 2, 2, 2);
	setMonsterDescription("An evil Goblin");
}

Goblin::~Goblin()
{
}
