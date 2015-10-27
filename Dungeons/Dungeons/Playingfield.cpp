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
	cout << "\n";
	Playingfield::getLegenda();
}

void Playingfield::getLegenda() {
	cout << "[[ Legenda: N = Normal room || P = Your location ]] \n";
}

void Playingfield::Generate()
{
	int startx = Globals::Random(10);
	int starty = Globals::Random(10);

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
