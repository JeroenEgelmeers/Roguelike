#include "stdafx.h"
#include "Square.h"

using namespace std;

Square::Square(int x, int y)
{
	this->x = x;
	this->y = y;
	symbol = ' ';
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
	left = new Hallway(this->x + 1, this->y);
	left->CreateNeighbours(x, y);
}

void Square::Drawfield()
{
	cout << symbol;
	if (left != nullptr)
		left->Drawfield();
	if (x == 0)
	{
		if (down != nullptr)
		{
			cout << '\n';
			down->Drawfield();
		}
	}
}



Square::~Square()
{
	delete this->up;
	delete this->left;
	delete this->right;
	delete this->down;
}
