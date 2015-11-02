#include "stdafx.h"
#include "Level.h"


Level::Level(int x, int y)
{
	int startx = Globals::Random(10);
	int starty = Globals::Random(10);
	int stairx = Globals::Random(10);
	int stairy = Globals::Random(10);

	while (stairx == startx && stairy == starty)
	{
		stairx = Globals::Random(10);
		stairy = Globals::Random(10);
	}

	if (startx == 0 && starty == 0)
	{
		startpoint = new Room(startx, starty, nullptr);
		topleft = startpoint;
	}
	else if (stairx == 0 && stairy == 0)
	{
		stairway = new Room(stairx, stairy, nullptr);
		topleft = stairway;
	}
	else
		topleft = new Room(0, 0, nullptr);
	
	
	topleft->CreateNeighbours(x, y);

	if (startpoint == nullptr)
		startpoint = topleft->GetRoom(startx, starty);
	if (stairway == nullptr)
		stairway = topleft->GetRoom(stairx, stairy);

	startpoint->SetSymbol('S');
	stairway->SetSymbol('T');
}

Level::Level(int x, int y, Hero heroadr)
{
	int startx = Globals::Random(10);
	int starty = Globals::Random(10);
	int stairx = Globals::Random(10);
	int stairy = Globals::Random(10);

	while (stairx == startx && stairy == starty)
	{
		stairx = Globals::Random(10);
		stairy = Globals::Random(10);
	}

	if (startx == 0 && starty == 0)
	{
		startpoint = new Room(startx, starty, nullptr);
		topleft = startpoint;
	}
	else if (stairx == 0 && stairy == 0)
	{
		stairway = new Room(stairx, stairy, nullptr);
		topleft = stairway;
	}
	else
		topleft = new Room(0, 0, nullptr);


	topleft->CreateNeighbours(x, y);

	if (startpoint == nullptr)
		startpoint = topleft->GetRoom(startx, starty);
	if (stairway == nullptr)
		stairway = topleft->GetRoom(stairx, stairy);

	startpoint->SetSymbol('S');
	stairway->SetSymbol('T');
	startpoint->player = &heroadr;
	heroadr.setRoom(startpoint);
}

void Level::Drawfield()
{
	topleft->Drawfield();
}

Level::~Level()
{
	delete topleft;
}
