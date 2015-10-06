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
}

void Playingfield::Generate()
{
	if (Squarelist == nullptr)
	{
		Squarelist = new Room(0, 0);
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
