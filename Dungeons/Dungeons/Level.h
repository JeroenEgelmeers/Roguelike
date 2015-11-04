#pragma once

class Level
{
public:
	Level(int x, int y, int level);
	~Level();
	void Drawfield();
	void SetPlayer();
	void ReturnPlayer();

	int level;
	Room* startpoint;
	Room* stairway;
	Square* topleft;
};

