#pragma once

class Level
{
public:
	Level(int x, int y);
	~Level();
	void Drawfield();
	void SetPlayer();
	void ReturnPlayer();

	Room* startpoint;
	Room* stairway;
	Square* topleft;
};

