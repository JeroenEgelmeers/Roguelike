#include "stdafx.h"
#include "Globals.h"

bool Globals::seeded = false;

int Globals::Random(int max)
{
	if (!seeded)
	{
		srand(time(0) * 1000);
		seeded = true;
	}
	return (rand() % max);
}