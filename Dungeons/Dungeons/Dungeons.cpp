// Dungeons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "Hero.h"
#include "InputController.h"
#include "Game.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Playingfield pf { 10, 10, 1 };
	pf.Generate();
	InputController::Instance().setPlayingField(&pf);

	string currentAction;
	// Begin beschrijving
	cout << "* Welcome By Roguelike! \n"
		 << "* Let's start! Please enter your name! \n";
	string userName;
	cin >> userName;
	
	Hero hero;
	if (hero.Instance().setUserName(userName)) {
		cout << "* Welcome " << userName << ". You're ready to start your adventure! \n";
	}else { cout << "* You've already set your username " << hero.Instance().userName << "! \n";  }
	cin.clear();
	hero.getHeroStats();
	cout << "* To enter the first room, type: !enterDungeon \n";
	cin >> currentAction;
	if (currentAction == "!enterDungeon") {
		system("CLS");
		cout << "* You entered the first room. \n";
		cout << "* Room description: TODO \n";
		Game::Instance().setGameLoop(true);
	}

	while (Game::Instance().getGameLoopStatus()) {
		InputController::Instance().CheckInput();
	}
	return 0;
}
