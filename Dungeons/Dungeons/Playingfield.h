#pragma once


using namespace std;

class Playingfield
{
public:
	Playingfield(int x, int y, int levels);
	~Playingfield();
	void Generate();
	void Drawfield();
	void getLegenda();
	void switchLevel(int level);
	void goLevelUp();
	void goLevelDown();
private:
	int xsize;
	int ysize;
	int lsize;
	int curlevel;
	vector<Level*> levels;
};

