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
	cout << "\n";
	Playingfield::getLegenda();
}

void Playingfield::getLegenda() {
	cout << "[[ Legenda: N = Normal room || P = Your location || T = Stairway Down || S = Startpoint/Stairway Up || -|]] \n";
}

void Playingfield::Generate()
{
	if (levels.size() != 0)
	{
		for each (Level* ptr in levels)
		{
			delete ptr;
		}
		this->Generate();
	}
	else
	{
		for (int i = 0; i < lsize; i++)
		{
			levels.push_back(new Level(xsize, ysize));
		}
		levels[0]->SetPlayer();
		curlevel = 0;
	}
	for each (Level* lv in levels)
	{
		cout << "level\n";
	}
}

void Playingfield::switchLevel(int level)
{
	levels[level]->SetPlayer();
}

void Playingfield::goLevelUp()
{
	if (curlevel < lsize)
		levels[curlevel-1]->SetPlayer();
}

void Playingfield::goLevelDown()
{
	if (curlevel > 0)
		levels[curlevel-1]->ReturnPlayer();
}

Playingfield::~Playingfield()
{
	for each (Level* ptr in levels)
	{
		delete ptr;
	}
}
