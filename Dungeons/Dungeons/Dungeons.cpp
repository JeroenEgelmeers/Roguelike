// Dungeons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Playingfield pf{ 10, 10, 1 };
	pf.Generate();
	pf.Drawfield();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return 0;
}

