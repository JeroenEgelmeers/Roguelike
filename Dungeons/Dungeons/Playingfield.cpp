#include "stdafx.h"
#include "Playingfield.h"

Playingfield::Playingfield(int x, int y, int levels)
{
	xsize = x;
	ysize = y;
	this->lsize = levels;
}

void Playingfield::Drawfield()
{
	levels[0]->Drawfield();
	cout << "\n";
	Playingfield::getLegenda();
}

void Playingfield::getLegenda() {
	cout << "[[ Legenda: N = Normal room || P = Your location ]] \n";
}

void Playingfield::Generate()
{
	for (int i = 0; i < lsize; i++)
	{
		if (levels.size() == 0)
		{
			levels.push_back(new Level(xsize, ysize));
		}
		else
		{
			for each (Level* ptr in levels)
			{
				delete ptr;
			}
			this->Generate();
			break;
		}
	}
}

Playingfield::~Playingfield()
{
	for each (Level* ptr in levels)
	{
		delete ptr;
	}
}
