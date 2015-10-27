#include "stdafx.h"
#include "Globals.h"

int Globals::Random(int max)
{
	srand(time(0) * 1000);
	return (rand() % max);
}

int Globals::Random(int min, int max)
{
	srand(time(0) * 1000);
	return (rand() % max) + min;
}