#pragma once
class Game
{
public:
	static Game& Instance() {
		static Game mInstance;
		return mInstance;
	}
	Game();
	~Game();

	bool setGameLoop(bool status);
	bool getGameLoopStatus();
	bool gameLoop;
};

