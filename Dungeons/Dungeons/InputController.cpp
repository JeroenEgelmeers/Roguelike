#include "stdafx.h"
#include "InputController.h"
#include "Playingfield.h"
#include "Hero.h"
#include "Game.h"
#include <string>
#include <algorithm>
using namespace std;

InputController::InputController(){}

InputController::~InputController(){}

void InputController::CheckInput() {
	string input;
	cout << "* What would you like to do? [ Press !help for more information ] \n";
	cin >> input;

	// Input to lowercase
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	
	// All commands
	if (input == "!help") { 
		// Normal help command
		cout << "* You can use one of the following commands: \n"
			<< "[[ Move to direction: !north - !east - !south - !west ]] \n"
			<< "[[ Player information: !stats ]] \n"
			<< "[[ Game information: !map ]] \n"
			<< "* end of commandlist. \n";
	}
	// Player commands
	else if (input == "!stats") { Hero::Instance()->getHeroStats(); }

	// Game commands
	else if (input == "!map") { pf->Drawfield(); }

	// Direction commands
	else if (input == "!north")		
	{ 
		Hero::Instance()->moveHero(0); 
		cout << "* You entered the next room. \n";
		cout << "* Room description: " + Hero::Instance()->getRoomDescription();
	}
	else if (input == "!east")		
	{ 
		Hero::Instance()->moveHero(1);
		cout << "* You entered the next room. \n";
		cout << "* Room description: " + Hero::Instance()->getRoomDescription();
	}
	else if (input == "!south")		
	{ 
		Hero::Instance()->moveHero(2); 
		cout << "* You entered the next room. \n";
		cout << "* Room description: " + Hero::Instance()->getRoomDescription();
	}
	else if (input == "!west")		
	{ 
		Hero::Instance()->moveHero(3); 
		cout << "* You entered the next room. \n";
		cout << "* Room description: " + Hero::Instance()->getRoomDescription();
	}

	// System commands
	else if (input == "!quit")		{ quitGame(); }
	
	// Cheat functions.
	else if (input == "@heal")		{ Hero::Instance()->addHealth(10); cout << "@CHEAT: you gained 10 HP! \n"; }

	// Errors
	else { cout << "* No command found." << endl; }
}

void InputController::setPlayingField(Playingfield* setPf) { pf = setPf; }

void InputController::quitGame()
{
	cout << "* You're not yet done " << Hero::Instance()->getUserName() << "! Are you sure to quit the game? Your progress will be lost! (Press: !yes or !no) \n";
	string input;
	cin >> input;
	if (input == "!yes") { Game::Instance().setGameLoop(false); }
	else { cout << "* Great! Let's keep playing! \n"; CheckInput(); } // Doesn't make any sense what a players types. Just keep playing :)!
}

