#include "stdafx.h"
#include "InputController.h"
#include "Hero.h"
#include "Game.h"
#include <string>
using namespace std;

InputController::InputController(){}

InputController::~InputController(){}

void InputController::CheckInput() {
	string input;
	cout << "* What would you like to do? [ Press !help for more information ]" << endl;
	cin >> input;
	
	// Switch with all possible commands ; switch with string doesn't work in C++
	if (input == "!help") { 
		// Normal help command
		cout << "* You can use one of the following commands:" << endl
			<< "[[ Move to direction: !north - !east - !south - !west ]]" << endl
			<< "[[ Player information: !stats ]]" << endl
			<< "* end of commandlist." << endl;
	}
	else if (input == "!stats") { Hero::Instance().getHeroStats(); }
	else if (input == "!north") { /* move north */ }
	else if (input == "!east") { /* move east */ }
	else if (input == "!south") { /* move south */ }
	else if (input == "!west") { /* move west */ }
	else if (input == "!quit") { quitGame(); }
	
	// Cheat functions.
	else if (input == "@heal") { Hero::Instance().addHealth(10); }
	else { cout << "* No command found." << endl; }
}

void InputController::quitGame()
{
	cout << "* You're not yet done " << Hero::Instance().getUserName() << "! Are you sure to quit the game? Your progress will be lost! (Press: !yes or !no)" << endl;
	string input;
	cin >> input;
	if (input == "!yes") { Game::Instance().setGameLoop(false); }
	else { cout << "* Great! Let's keep playing!" << endl; CheckInput(); } // Doesn't make any sense what a players types. Just keep playing :)!
}

