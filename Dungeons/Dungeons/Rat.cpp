#include "stdafx.h"
#include "Rat.h"


Rat::Rat(int multiplier) : Monster()
{
	// Hard coded, can be changed later..
	setMonsterName("Rat");
	setStats(3 * multiplier, 4 * multiplier, 2 * multiplier, 2 * multiplier, 2 * multiplier);
	setMonsterDescription("A giant rat");
}

Rat::~Rat()
{

}
