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
	levels[curlevel]->Drawfield();
	cout << "\n" << "Level " << curlevel << "\n";
	Playingfield::getLegenda();
}

void Playingfield::getLegenda() {
	cout << "[[ Legenda: N = Normal room || P = Your location || T = Stairway Down || S = Startpoint/Stairway Up || -| = Hallway ]] \n";
}

void Playingfield::Generate()
{
	if (levels.size() != 0)
	{
		for each (Level* ptr in levels)
		{
			delete ptr;
		}
		Globals::itemlist.clear();
		this->Generate();
	}
	else
	{
		for (int x = 0; x < 21; x++)
		{
			Globals::itemlist.push_back(x);
		}

		// elke kamer, min de trappen, min degene met een item
		for (int x = 0; x < ((xsize*ysize*lsize) - (2 * lsize)) - 21; x++)
			Globals::itemlist.push_back(-1);

		shuffle(Globals::itemlist.begin(), Globals::itemlist.end(), default_random_engine(Globals::Random(100)));

		for (int i = 0; i < lsize; i++)
		{
			levels.push_back(new Level(xsize, ysize));
		}
		levels[0]->SetPlayer();
		curlevel = 0;
	}
}

void Playingfield::switchLevel(int level)
{
	levels[level]->SetPlayer();
	curlevel = level;
}

void Playingfield::goLevelUp()
{
	curlevel++;
	if (curlevel < lsize)
		levels[curlevel]->SetPlayer();
}

void Playingfield::goLevelDown()
{
	curlevel--;
	if (curlevel > 0)
		levels[curlevel]->ReturnPlayer();
}

Playingfield::~Playingfield()
{
	for each (Level* ptr in levels)
	{
		delete ptr;
	}
}
