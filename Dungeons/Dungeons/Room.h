#pragma once
#include "Monster.h"
#include <string>

using namespace std;

class Room: public Square
{
public:
	Room(int x, int y, Square* parrent);
	~Room();

	void CreateNeighbours(int x, int y);
	void generateRoomDescription();
	void setRoomType(int type);
	Room* GetRoom(int x, int y);
	string GetDescription();
	Monster GetMonster();
private:
	string generateRoomType(int type);
	Monster mob;
	string description;
	string roomType;
	unsigned char roomSymbol;
};

