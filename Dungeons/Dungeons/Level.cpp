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
	startpoint->setSpecialDescription(0);
	stairway->setSpecialDescription(1);

	stairway->special = 2;
	startpoint->special = 1;

	cout << "\n" << stairway->GetX() << " " << stairway->GetY() << "\n";

	stairway->SetMonster(new Boss());

	startpoint->player = Hero::Instance();

	if (startpoint != nullptr)
	{
		if (startpoint->up != nullptr)
			startpoint->up->visible = true;
		if (startpoint->left != nullptr)
			startpoint->left->visible = true;
		if (startpoint->down != nullptr)
			startpoint->down->visible = true;
		if (startpoint->right != nullptr)
			startpoint->right->visible = true;
	}
}

void Level::SetPlayer()
{
	Hero::Instance()->setRoom(startpoint);
}

void Level::ReturnPlayer()
{
	Hero::Instance()->setRoom(stairway);
}

void Level::Drawfield()
{
	topleft->Drawfield();
}

Level::~Level()
{
	delete topleft;
}
