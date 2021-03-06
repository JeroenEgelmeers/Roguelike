#include "stdafx.h"
#include "Room.h"

Room::Room(int x, int y, Square* parrent, Level* level) : Square(x, y, parrent, level)
{
	special = 0;
	description = "Geen Beschrijving";
	int healerRandom = rand() % 5;
	if (healerRandom == 1) {
		healer = true; generateRoomType(6);
	}
	else { healer = false;  generateRoomType(0); }

	int trapRandom = rand() % 8;
	if (trapRandom == 1) {
		hasTrap = true;
		generateTrap();
	}
	else { hasTrap = false; }

	generateRoomDescription();
	generateMonster();
	if (Globals::itemlist.size() >= 1)
	{
		if (Globals::itemlist.back() != -1)
		{
			item = new Item();
			item->generateItem(Globals::itemlist.back());
		}
		Globals::itemlist.pop_back();
	}
}

void Room::removeTrap() {
	hasTrap = false;
}

int Room::getTrapKind() {
	return trapLevel;
}

void Room::generateTrap() {
	int trapRandom = rand() % 7 + 1;
	trapLevel = trapRandom;
}

bool Room::getTrap()
{
	return hasTrap;
}

Item* Room::GetItem()
{
	if (item != nullptr) {
		return item;
	}
	else {
		return nullptr;
	}
}

void Room::RemoveMonster() {
	monster = nullptr;
}

void Room::RemoveItem()
{
	item = nullptr;
}

void Room::CreateNeighbours(int x, int y)
{
	if (x > 0)
	{
		right = new Hallway(this->x + 1, this->y, this, level);
		right->CreateNeighbours(x - 1, y);
	}
	if (this->x == 0 && y > 0)
	{
		down = new Hallway(this->x, this->y + 1, this, level);
		down->CreateNeighbours(x, y - 1);
	}
}

void Room::generateRoomDescription() {
	string description = " A ";

	string roomDescriptions_0[7]{ "clean", "dirty", "scary", "bloody", "smelly", "dusty", "fancy" };
	string roomDescriptions_1[9]{ "big room", "normal room", "small room", "living room", "kitchen", "bathroom", "bedroom", "work room", "games room" };
	string roomDescriptions_2[5]{ "with nothing in it.", "with in the middle a table", "with in the middle a lamp", "with in the middle a skeleton", "with in the middle an computer" };
	string roomDescriptions_3[13]{ "a skeleton", "a basket", "a chest", "a bar", "a wheel", "a bureau", "a globe", "a phone", "a bed", "a painting", "a shelf", "some shoes", "some broken glass" };

	int getDescription = Globals::Random(7);
	description += roomDescriptions_0[getDescription];

	getDescription = Globals::Random(9); // 0-5
	description += " " + roomDescriptions_1[getDescription];

	getDescription = Globals::Random(5);
	description += " " + roomDescriptions_2[getDescription];

	if (getDescription > 0) {
		getDescription = Globals::Random(13);
		description += " and in the corner " + roomDescriptions_3[getDescription];
	}
	description += "\n";

	this->description = description;

	if (this->description == "")
	{
		this->description = "\n An anomalys room lacking a clear description \n";
	}
}

void Room::setSpecialDescription(int id)
{
	string roomDescriptions_0[]{ "clean", "dirty", "scary", "bloody", "smelly", "dusty", "fancy"};
	int getDescription;
	switch (id)
	{
	case 0:
		description = "\n A ";
		getDescription = Globals::Random(7);
		description += roomDescriptions_0[getDescription];
		description += " stairway from where you entered the floor\n";
		break;
	case 1:
		description = "\n A ";
		getDescription = Globals::Random(7);
		description += roomDescriptions_0[getDescription];
		description += " stairway down to the next floor\n";
		break;
	default:
		description = "\n An anomalys room lacking a clear description \n";
		break;
	}
}

string Room::generateRoomType(int type) {
	string returnString;
	switch (type)
	{
	case 0:
		returnString	= "Normal room";
		symbol = 'N';
		break;
	case 1:
		returnString	= "Pitfall";
		symbol = 'X';
		break;
	case 2:
		returnString	= "Stairs Down";
		symbol = 'v';
		break;
	case 3:
		returnString	= "Stairs Up";
		symbol = '^';
		break;
	case 4:
		returnString	= "Enemy room";
		symbol = 'E';
		break;
	case 5:
		returnString	= "Boss room";
		symbol = 'B';
		break;
	case 6:
		returnString = "Heal room";
		symbol = 'H';
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

void Room::Drawfield()
{
	if (player != nullptr)
		cout << 'P';
	else
	{
		if (visible)
			cout << symbol;
		else
			cout << '.';
	}

	if (right != nullptr)
		right->Drawfield();
	if (x == 0)
	{
		if (down != nullptr)
		{
			cout << '\n';
			down->Drawfield();
		}
	}
}

bool Room::MovePlayer(int direction)
{
	Room* nextrm = nullptr;
	switch (direction)
	{
	case 0:
		if (up != nullptr)
		{
			nextrm = dynamic_cast<Room*>(up->up);
			nextrm->player = this->player;
			this->player->setRoom(nextrm);
			this->player = nullptr;
			this->visible = true;
		}
		else
			return false;
		break;
	case 1:
		if (right != nullptr)
		{
			nextrm = dynamic_cast<Room*>(right->right);
			nextrm->player = this->player;
			this->player->setRoom(nextrm);
			this->player = nullptr;
			this->visible = true;
		}
		else
			return false;
		break;
	case 2:
		if (down != nullptr)
		{
			nextrm = dynamic_cast<Room*>(down->down);
			nextrm->player = this->player;
			this->player->setRoom(nextrm);
			this->player = nullptr;
			this->visible = true;
		}
		else
			return false;
		break;
	case 3:
		if (left != nullptr)
		{
			nextrm = dynamic_cast<Room*>(left->left);
			nextrm->player = this->player;
			this->player->setRoom(nextrm);
			this->player = nullptr;
			this->visible = true;
		}
		else
			return false;
		break;
	default:
		break;
	}
	if (nextrm != nullptr)
	{
		if (nextrm->up != nullptr)
			nextrm->up->visible = true;
		if (nextrm->left != nullptr)
			nextrm->left->visible = true;
		if (nextrm->down != nullptr)
			nextrm->down->visible = true;
		if (nextrm->right != nullptr)
			nextrm->right->visible = true;
	}
	return true;
}


void Room::generateMonster()
{
	int randomMonster = rand() % 10;
	switch (randomMonster) {
	case 0:
		monster = new Rat(level->level);
		break;
	case 1:
		monster = new Goblin(level->level);
		break;
	default:
		// No monster
		break;
	}
}


Monster* Room::GetMonster()
{
	if (monster != nullptr) {
		return monster;
	}
	else {
		return nullptr;
	}
}

void Room::SetMonster(Monster* mon)
{
	monster = mon;
}

Room::~Room()
{
}
