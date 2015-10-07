#pragma once
#include "Square.h"
#include "Monster.h"


using namespace std;

class Room: public Square
{
public:
	Room(int x, int y, Square* parrent);
	~Room();
	void CreateNeighbours(int x, int y);
	string GetDescription();
	Monster GetMonster();
private:
	Monster Mob;
	string Description;
};

