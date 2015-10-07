#include "stdafx.h"
#include "Square.h"

using namespace std;

Square::Square(int x, int y, Square* parrent)
{
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

string Square::RandomPath(int steps)
{
	Square* destination = this->down->right->up;
	for (int x = 0; x < steps; x++)
	{
		int nr = rand() % 4;
		cout << to_string(nr) + "\n";
		switch (nr)
		{
		case 0:
			if (up != nullptr)
				destination = destination->up;
			else
				x--;
			break;
		case 1:
			if (left != nullptr)
				destination = destination->left;
			else
				x--;
			break;
		case 2:
			if (right != nullptr)
				destination = destination->right;
			else
				x--;
			break;
		case 3:
			if (down != nullptr)
				destination = destination->down;
			else
				x--;
			break;
		default:
			break;
		} 
	}

	return "x = " + to_string(destination->x) + " | y = " + to_string(destination->y);
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
	right = new Hallway(this->x + 1, this->y, this);
	right->CreateNeighbours(x, y);
}

void Square::Drawfield()
{
	cout << symbol;
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



Square::~Square()
{
	delete this->right;
	delete this->down;
}
