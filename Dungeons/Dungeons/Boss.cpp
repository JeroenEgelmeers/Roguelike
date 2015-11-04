#include "stdafx.h"
#include "Boss.h"


Boss::Boss(int multiplier) : Monster()
{
	// Hard coded, can be changed later..
	setMonsterName("Boss - Elvrag");
	setStats(5 * multiplier, 6 * multiplier, 4 * multiplier, 4 * multiplier, 4 * multiplier);
	setMonsterDescription("A powerfull dragon");
}

Boss::~Boss() { }
