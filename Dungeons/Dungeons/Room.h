#pragma once
#include "Monster.h"
#include "Goblin.h"
#include "Rat.h"
#include "Boss.h"
#include "Hero.h"
#include "Item.h"
#include <string>

using namespace std;

class Level;

class Room: public Square
{
public:
	Room(int x, int y, Square* parrent, Level* level);
	~Room();

	void		CreateNeighbours(int x, int y);
	void		setRoomType(int type);
	void		Drawfield();
	Room*		GetRoom(int x, int y);
	string		GetDescription();
	Monster*	GetMonster();
	void		RemoveMonster();
	Hero*		player;
	void		setSpecialDescription(int id);
	bool		MovePlayer(int direction);
	bool		healer;
	bool		getTrap();
	int			getTrapKind();
	void		removeTrap();
	Item*		GetItem();
	void		RemoveItem();
	bool		special;
	void		SetMonster(Monster* mon);
	
private:
	string		generateRoomType(int type);
	Item*		item;
	Monster*	monster;
	string		description;
	string		 roomType;
	bool		hasTrap;
	int			trapLevel;
	unsigned char roomSymbol;
	void		generateRoomDescription();
	void		generateMonster();
	void		generateTrap();
};

