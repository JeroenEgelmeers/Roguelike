#include "stdafx.h"
#include "InputController.h"
#include "Playingfield.h"
#include "Hero.h"
#include "Game.h"
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
			<< "[[ Move to direction:\t !north - !east - !south - !west ]] \n"
			<< "[[ Player information:\t !stats - !inventory ]] \n"
			<< "[[ Game information:\t !map ]] \n"
			<< "[[ Climb Stairs:\t !climb ]] \n"
			<< "* end of commandlist. \n";
	}
	// Player commands
	else if (input == "!stats") { Hero::Instance()->getHeroStats(); }

	// Game commands
	else if (input == "!map") { pf->Drawfield(); }

	// Direction commands
	else if (input == "!north")
	{	
		if (Hero::Instance()->moveHero(0)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			monsterDetection();
		}
		else {
			cout << "[!] You can't go that way! Go to another direction: [ !east - !south - !west ] \n";
		}
	}
	else if (input == "!east")
	{
		if (Hero::Instance()->moveHero(1)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			monsterDetection();
		}
		else {
			cout << "[!] You can't go that way! Go to another direction: [ !north - !south - !west ] \n";
		}
	}
	else if (input == "!south")
	{
		if (Hero::Instance()->moveHero(2)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			monsterDetection();
		}
		else {
			cout << "[!] You can't go that way! Go to another direction: [ !north - !east - !west ] \n";
		}
	}
	else if (input == "!west")
	{
		if (Hero::Instance()->moveHero(3)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			monsterDetection();
		}
		else {
			cout << "You can't go that way! Go to another direction: [ !north - !east - !south ] \n";
		}
	}
	else if (input == "!inventory") {
		cout << inventory.getItems();
	}
	else if (input == "!getitem") {
		cout << "This function is not yet implemented! \n";
		//inventory.addItem(item);
	
		// cout << "You did just pick + item.getItemName";
	}

	else if (input == "!climb")		
	{ 
		if (Hero::Instance()->getStairway())
		{
			if (Hero::Instance()->getRoom()->special == 1)
				pf->goLevelUp();
			else
				pf->goLevelDown();
		}
		else
			cout << "You are not standing on a stairway";
	}

	// System commands
	else if (input == "!quit")		{ quitGame(); }

	
	// Cheat functions.
	else if (input == "@heal")		{ Hero::Instance()->addHealth(10); cout << "@CHEAT: you gained 10 HP! \n"; }

	// Errors
	else { cout << "* No command found." << endl; }
	cout << "\n";
}

void InputController::monsterDetection() {
	if (Hero::Instance()->getRoom()->GetMonster() != nullptr)
	{
		cout << "/!\\ Watch out! There is a something in this room!\n";
		Hero::Instance()->getRoom()->GetMonster()->getMonsterStats();
	}
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

