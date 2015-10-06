#pragma once
#include "Square.h"

class Hallway: public Square
{
public:
	Hallway(int x, int y);
	~Hallway();
	void CreateNeighbours(int x, int y);
	bool IsAccessable();
	void Collapse();
private:
	bool Accesable;
};

