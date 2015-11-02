#pragma once


using namespace std;

class Playingfield
{
public:
	Playingfield(int x, int y, int levels);
	~Playingfield();
	void Generate(Hero heroadr);
	void Drawfield();
	void getLegenda();
private:
	int xsize;
	int ysize;
	int lsize;
	vector<Level*> levels;
};

