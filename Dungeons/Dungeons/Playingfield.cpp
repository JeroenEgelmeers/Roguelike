#include "stdafx.h"
#include "Playingfield.h"


Playingfield::Playingfield(int x, int y, int levels)
{
	xsize = x;
	ysize = y;
	this->levels = levels;
}

void Playingfield::Drawfield()
{
	Squarelist->Drawfield();
	cout << "\n\n";
	//cout << Squarelist->RandomPath(100);
}

void Playingfield::Generate()
{
	if (Squarelist == nullptr)
	{
		Squarelist = new Room(0, 0, nullptr);
		Squarelist->CreateNeighbours(xsize, ysize);
	}
	else
	{
		delete Squarelist;
		this->Generate();
	}
}

Playingfield::~Playingfield()
{
	delete Squarelist;
}
