#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::setGameLoop(bool status)
{
	gameLoop = status;
	return gameLoop;
}

bool Game::getGameLoopStatus()
{
	return gameLoop;
}

