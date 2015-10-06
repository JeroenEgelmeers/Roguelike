#pragma once
#include "Square.h"
#include "Monster.h"
#include <string>

using namespace std;

class Room: public Square
{
public:
	Room(int x, int y);
	~Room();
	void CreateNeighbours(int x, int y);
	string GetDescription();
	Monster GetMonster();
private:
	Monster Mob;
	string Description;
};

