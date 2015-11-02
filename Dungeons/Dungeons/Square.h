#pragma once

class Room;

class Square
{
public:
	Square(int x, int y, Square* parrent);
	~Square();
	int GetX();
	int GetY();
	void Drawfield();
	virtual void CreateNeighbours(int x, int y);
	virtual Room* GetRoom(int x, int y);
protected:
	int x;
	char symbol;
	int y;
	Square* up;
	Square* left;
	Square* right;
	Square* down;
};

