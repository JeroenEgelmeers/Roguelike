#pragma once

class Level
{
public:
	Level(int x, int y);
	~Level();
	void Drawfield();

	Room* startpoint;
	Room* stairway;
	Square* topleft;
};

