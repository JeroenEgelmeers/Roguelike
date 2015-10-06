#include "stdafx.h"
#include "Hallway.h"


Hallway::Hallway(int x, int y) : Square(x, y)
{
	if (y % 2 == 0)
		symbol = '-';
	else
		symbol = '|';
}

void Hallway::CreateNeighbours(int x, int y)
{
	if (this->y % 2 == 0)
	{
		left = new Room(this->x + 1, this->y);
		left->CreateNeighbours(x, y);
	}
	else
	{
		if (x > 0)
		{
			left = new Square(this->x + 1, this->y);
			left->CreateNeighbours(x - 1, y);
		}
		if (this->x == 0)
		{
			down = new Room(this->x, this->y + 1);
			down->CreateNeighbours(x, y);
		}
	}
}

Hallway::~Hallway()
{
}
