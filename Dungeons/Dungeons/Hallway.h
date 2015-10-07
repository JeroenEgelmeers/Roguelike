#pragma once
#include "Square.h"

class Hallway: public Square
{
public:
	Hallway(int x, int y, Square* parrent);
	~Hallway();
	void CreateNeighbours(int x, int y);
	bool IsAccessable();
	void Collapse();
private:
	bool Accesable;
};

