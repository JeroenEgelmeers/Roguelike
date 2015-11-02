#pragma once

class Level
{
public:
	Level(int x, int y);
	~Level();
	void Drawfield();
	void SetPlayer();

	Room* startpoint;
	Room* stairway;
	Square* topleft;
};

