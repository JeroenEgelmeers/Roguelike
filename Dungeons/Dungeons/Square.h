#pragma once
#include <string>

using namespace std;

class Square
{
public:
	Square(int x, int y, Square* parrent);
	~Square();
	int GetX();
	int GetY();
	void Drawfield();
	virtual void CreateNeighbours(int x, int y);
	string RandomPath(int steps);
protected:
	int x;
	char symbol;
	int y;
	Square* up;
	Square* left;
	Square* right;
	Square* down;
};

