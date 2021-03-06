#include "stdafx.h"
#include "Square.h"

using namespace std;

Square::Square(int x, int y, Square* parrent, Level* level)
{
	this->level = level;

	this->x = x;
	this->y = y;
	symbol = ' ';

	if (x == 0)
		up = parrent;
	else
	{
		left = parrent;
		
		if (y != 0)
		{
			left->up->right->down = this;
			up = left->up->right;
		}
	}
}

int Square::GetX()
{
	return x;
}

int Square::GetY()
{
	return y;
}

void Square::CreateNeighbours(int x, int y)
{
	// empty squares are never on edges, and are only and always surrounded by hallways
	right = new Hallway(this->x + 1, this->y, this, level);
	right->CreateNeighbours(x, y);
}

void Square::Drawfield()
{
	if (visible || symbol == ' ')
		cout << symbol;
	else
		cout << '.';

	if (right != nullptr)
		right->Drawfield();
	if (x == 0)
	{
		if (down != nullptr)
		{
			cout << '\n';
			down->Drawfield();
		}
	}
}

void Square::SetSymbol(char c)
{
	symbol = c;
}

Room* Square::GetRoom(int x, int y)
{
	if (x > (this->x / 2))
		return this->right->GetRoom(x, y);
	else
		return this->down->GetRoom(x,y);
}

Square::~Square()
{
	//delete this->up;
	//delete this->left;
	//delete this->right;
	//delete this->down;
}
