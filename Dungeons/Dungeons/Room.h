#pragma once
#include "Monster.h"
#include "Goblin.h"
#include "Rat.h"
#include "Boss.h"
#include "Hero.h"
#include "Item.h"
#include <string>

using namespace std;

class Room: public Square
{
public:
	Room(int x, int y, Square* parrent);
	~Room();

	void		CreateNeighbours(int x, int y);
	void		setRoomType(int type);
	void		Drawfield();
	Room*		GetRoom(int x, int y);
	string		GetDescription();
	Monster*	GetMonster();
	Hero*		player;
	void		setSpecialDescription(int id);
	bool		MovePlayer(int direction);
	Item*		GetItem();
	void		RemoveItem();
	bool		special;
private:
	string		generateRoomType(int type);
	Item*		item;
	Monster*	monster;
	string		description;
	string		 roomType;
	unsigned char roomSymbol;
	void		generateRoomDescription();
	void		generateMonster();
};

