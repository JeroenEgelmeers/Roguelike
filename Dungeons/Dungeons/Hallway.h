#pragma once
#include "Square.h"

class Level;

class Hallway: public Square
{
public:
	Hallway(int x, int y, Square* parrent, Level* level);
	~Hallway();
	void CreateNeighbours(int x, int y);
	bool IsAccessable();
	void Collapse();
private:
	bool Accesable;
};

