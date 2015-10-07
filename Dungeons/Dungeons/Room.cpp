#include "stdafx.h"
#include "Room.h"


Room::Room(int x, int y) : Square(x, y)
{
	Description = "Geen Beschrijving";
	symbol = 'N';
}

void Room::CreateNeighbours(int x, int y)
{
	if (x > 0)
	{
		left = new Hallway (this->x+1, this->y);
		left->CreateNeighbours(x - 1, y);
	}
	if (this->x == 0 && y > 0)
	{
		down = new Hallway(this->x, this->y + 1);
		down->CreateNeighbours(x, y - 1);
	}
}

string Room::GetDescription()
{
	return Description;
}

Monster Room::GetMonster()
{
	return Mob;
}

Room::~Room()
{
}
