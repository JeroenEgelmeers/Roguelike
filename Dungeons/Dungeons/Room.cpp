#include "stdafx.h"
#include "Room.h"


Room::Room(int x, int y, Square* parrent) : Square(x, y, parrent)
{
	description = "Geen Beschrijving";
	symbol = 'N';
}

void Room::CreateNeighbours(int x, int y)
{
	if (x > 0)
	{
		right = new Hallway(this->x + 1, this->y, this);
		right->CreateNeighbours(x - 1, y);
	}
	if (this->x == 0 && y > 0)
	{
		down = new Hallway(this->x, this->y + 1, this);
		down->CreateNeighbours(x, y - 1);
	}
}

void Room::generateRoomDescription() {
	string description = "Description: A";
	
	string roomDescriptions_0[6]{ " clean", " dirty", " scary", " bloody", " smelly", " dusty"};
	string roomDescriptions_1[8] {" big room", " normal room", " small room", " living room", " kitchen", "bathroom", "bedroom", "work room"};
	string roomDescriptions_2[5] { " with nothing in it.", " with in the middle a table", " with in the middle a lamp", " with in the middle a skaleton", " with in the middle an computer" };
	string roomDescriptions_3[13]{ " a skeleton", " a basket", " a chest", "a bar", "a wheel", "a bureau", "a globe", "a phone", "a bed", "a painting", "a shelf", "some shoes", "some broken glass" };

	int getDescription = rand() % 7;
	description += roomDescriptions_0[getDescription];

	getDescription = rand() % 9; // 0-5
	description += roomDescriptions_1[getDescription];

	getDescription = rand() % 6;
	description += roomDescriptions_2[getDescription];

	if (getDescription > 0) {
		getDescription = rand() % 10;
		description += "and in the corner" + roomDescriptions_3[getDescription];
	}
}

string Room::generateRoomType(int type) {
	string returnString;
	switch (type)
	{
	case 0:
		returnString	= "Normal room";
		roomSymbol		= 'N';
		break;
	case 1:
		returnString	= "Pitfall";
		roomSymbol		= 'X';
		break;
	case 2:
		returnString	= "Stairs Down";
		roomSymbol		= 'v';
		break;
	case 3:
		returnString	= "Stairs Up";
		roomSymbol		= '^';
		break;
	case 4:
		returnString	= "Enemy room";
		roomSymbol		= 'E';
		break;
	case 5:
		returnString	= "Boss room";
		roomSymbol		= 'B';
		break;
	default:
		// This should NEVER been used.
		break;
	}

	return returnString;
}

void Room::setRoomType(int type) {
	roomType = generateRoomType(type);
}

string Room::GetDescription()
{
	return description;
}

Room* Room::GetRoom(int x, int y)
{
	if (x == (this->x / 2) && y == (this->y / 2))
		return this;
	else if (x > (this->x / 2))
		return this->right->GetRoom(x, y);
	else
		return this->down->GetRoom(x, y);
}

Monster Room::GetMonster()
{
	return mob;
}

Room::~Room()
{
}
