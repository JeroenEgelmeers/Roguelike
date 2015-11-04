#include "stdafx.h"
#include "Boss.h"


Boss::Boss() : Monster()
{
	// Hard coded, can be changed later..
	setMonsterName("Boss - Elvrag");
	setStats(5, 6, 4, 4, 4);
	setMonsterDescription("A powerfull dragon");
}

Boss::~Boss() { }
