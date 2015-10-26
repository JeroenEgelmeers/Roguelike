#pragma once
#include "Square.h"
#include "Room.h"
#include "Hallway.h"

class Playingfield
{
public:
	Playingfield(int x, int y, int levels);
	~Playingfield();
	void Generate();
	void Drawfield();

	void getLegenda();

private:
	Square* Squarelist;
	int xsize;
	int ysize;
	int levels;
};

