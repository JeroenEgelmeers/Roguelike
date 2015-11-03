#pragma once
#include "Monster.h"
#include "Hero.h"
#include "Item.h"
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
	void Drawfield();
	Room* GetRoom(int x, int y);
	string GetDescription();
	Monster GetMonster();
	Hero* player;
	void setSpecialDescription(int id);
	void MovePlayer(int direction);
private:
	string generateRoomType(int type);
	Monster mob;
	Item item;
	string description;
	string roomType;
	unsigned char roomSymbol;
};

