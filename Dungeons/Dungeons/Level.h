#pragma once

class Level
{
public:
	Level(int x, int y);
	Level(int x, int y, Hero heroadr);
	~Level();
	void Drawfield();

	Room* startpoint;
	Room* stairway;
	Square* topleft;
};

