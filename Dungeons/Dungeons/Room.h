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
	void generateRoomDescription();
	void setRoomType(int type);
	string GetDescription();
	Monster GetMonster();
private:
	string generateRoomType(int type);

	Monster mob;
	string description;
	string roomType;
	unsigned char roomSymbol;
};

