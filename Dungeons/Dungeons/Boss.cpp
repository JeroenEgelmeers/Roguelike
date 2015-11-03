#include "stdafx.h"
#include "Boss.h"


Boss::Boss() : Monster()
{
	// Hard coded, can be changed later..
	setMonsterName("Boss - Elvrag");
	setStats(3, 4, 2, 2, 2);
	setMonsterDescription("A powerfull dragon");
}

Boss::~Boss() { }
