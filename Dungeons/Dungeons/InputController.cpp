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
			<< "[[ Climb Stairs:\t !climb ]] \n"
			<< "[[ Game information:\t !map - !attack - !heal ]] \n"
			<< "[[ Game options:\t !quit ]] \n"
			<< "* end of commandlist. \n";
	}
	// Player commands
	else if (input == "!stats" && Hero::Instance()->gamePlaying()) { Hero::Instance()->getHeroStats(); }

	// Game commands
	else if (input == "!map" && Hero::Instance()->gamePlaying()) { pf->Drawfield(); }

	// Direction commands
	else if (input == "!north" && Hero::Instance()->gamePlaying())
	{	
		if (Hero::Instance()->moveHero(0)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			itemDetection();
			monsterDetection();
		}
		else {
			cout << "[!] You can't go that way! Go to another direction: [ !east - !south - !west ] \n";
		}
	}
	else if (input == "!east" && Hero::Instance()->gamePlaying())
	{
		if (Hero::Instance()->moveHero(1)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			itemDetection();
			monsterDetection();
		}
		else {
			cout << "[!] You can't go that way! Go to another direction: [ !north - !south - !west ] \n";
		}
	}
	else if (input == "!south" && Hero::Instance()->gamePlaying())
	{
		if (Hero::Instance()->moveHero(2)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			itemDetection();
			monsterDetection();
		}
		else {
			cout << "[!] You can't go that way! Go to another direction: [ !north - !east - !west ] \n";
		}
	}
	else if (input == "!west" && Hero::Instance()->gamePlaying())
	{
		if (Hero::Instance()->moveHero(3)) {
			cout << "* You entered the next room. \n";
			cout << "* Room description: " + Hero::Instance()->getRoomDescription();
			itemDetection();
			monsterDetection();
		}
		else {
			cout << "You can't go that way! Go to another direction: [ !north - !east - !south ] \n";
		}
	}
	else if (input == "!attack" && Hero::Instance()->gamePlaying()) {
		if (Hero::Instance()->getRoom()->GetMonster() != nullptr) {
			attackMonster();
		}
		else {
			cout << "You're doing some amazing tricks with your sword, but hitting anything.. Nope! There is nothing in here!";
		}
	}
	// INVENTORY 
	else if (input == "!inventory" && Hero::Instance()->gamePlaying()) {
		cout << inventory.getItems();
	}
	else if (input == "!getitem" && Hero::Instance()->gamePlaying()) {
		if (Hero::Instance()->getRoom()->GetItem() != nullptr) {
			inventory.addItem(Hero::Instance()->getRoom()->GetItem());
			Hero::Instance()->getRoom()->RemoveItem();
			cout << "Item added to your inventory! \n";
		}
		else {
			cout << "There is no item in this room!";
		}
	}
	//
	else if (input == "!disarm" && Hero::Instance()->gamePlaying()) {
		if (Hero::Instance()->getRoom()->getTrap()) {
			Hero::Instance()->getRoom()->removeTrap();
			cout << "Well done! You just disarmed a trap in this room.";
		}
		else {
			cout << "No traps in here! You're safe!";
		}
	}

	// HEALING
	else if (input == "!heal" && Hero::Instance()->gamePlaying()) {
		if (Hero::Instance()->getRoom()->healer) {
			if (Hero::Instance()->healHero()) {
				cout << "You just healed yourself at a magic stone!!";
			}
			else {
				cout << "You're already full health!";
			}
		}
		else {
			cout << "There is no healer in this room. You can find descovered healing points in your map defined with \"H\"!";
		}
	}

	else if (input == "!climb")		
	{ 
		if (Hero::Instance()->getStairway())
		{
			if (Hero::Instance()->getRoom()->special == 1)
			{
				cout << "You climbed the stairs down";
				pf->goLevelUp();
			}
			else
			{
				pf->goLevelDown();
				cout << "You climbed the stairs back up";
			}
			
		}
		else
			cout << "You are not standing on a stairway";
	}

	// System commands
	else if (input == "!quit")		{ quitGame(); }

	
	// Cheat functions.
	else if (input == "@heal")		{ Hero::Instance()->addHealth(10); cout << "@CHEAT: you gained 10 HP! \n"; }

	else if (Hero::Instance()->gameOver) { cout << "You lost. Please press: !quit and restart the game!"; }
	else if (Hero::Instance()->gameWon) { cout << "You WON! Please press: !quit and restart the game!"; }
	// Errors
	else { cout << "* No command found." << endl; }

	cout << "\n";
}

void InputController::attackMonster() {
	int hit = (Hero::Instance()->getAttack() + Hero::Instance()->getStrength() + 1 - Hero::Instance()->getRoom()->GetMonster()->getDefence());
	int playerHit = 0;
	if (hit > 0) {
		playerHit = rand() % hit;
	}
	Hero::Instance()->getRoom()->GetMonster()->removeHealth(playerHit);
	cout << "You used your sword and hit: " << playerHit << "! \n";
	if (Hero::Instance()->getRoom()->GetMonster()->getHealth() <= 0) {
		cout << "Awesome! You just killed the " << Hero::Instance()->getRoom()->GetMonster()->getMonsterName() << "! \n";
		Hero::Instance()->increaseXp((Hero::Instance()->getRoom()->GetMonster()->getLevel() * 7));
		Hero::Instance()->getRoom()->RemoveMonster();
	}
	else {
		Hero::Instance()->getRoom()->GetMonster()->getMonsterStats();
		hit = (Hero::Instance()->getRoom()->GetMonster()->getAttack() + Hero::Instance()->getRoom()->GetMonster()->getStrength() - Hero::Instance()->getDefence());
		int monsterHit = 0;
		if (hit > 0) {
			monsterHit = rand() % hit;
		}
		
		cout << "The " << Hero::Instance()->getRoom()->GetMonster()->getMonsterName() << " hits " << monsterHit << "! \n";
		Hero::Instance()->removeHealth(monsterHit);
		if (Hero::Instance()->getHealth() > 0) {
			Hero::Instance()->getHeroStatsFight();
		}
	}
}

void InputController::itemDetection() {
	if (Hero::Instance()->getRoom()->GetItem() != nullptr) {
		cout << "THERE IS AN ITEM IN THIS ROOM! \n";
	}
}

void InputController::monsterDetection() {
	if (Hero::Instance()->getRoom()->GetMonster() != nullptr)
	{
		cout << "/!\\ WATCH OUT! There is a something in this room!\n";
		Hero::Instance()->getRoom()->GetMonster()->getMonsterStats();
	}
}

void InputController::setPlayingField(Playingfield* setPf) { pf = setPf; }

void InputController::quitGame()
{
	if (Hero::Instance()->gameOver || Hero::Instance()->gameWon) {
		cout << "See ya!";
	}
	else {
		cout << "* You're not yet done " << Hero::Instance()->getUserName() << "! Are you sure to quit the game? Your progress will be lost! (Press: !yes or !no) \n";
		string input;
		cin >> input;
		if (input == "!yes") { Game::Instance().setGameLoop(false); }
		else { cout << "* Great! Let's keep playing! \n"; CheckInput(); } // Doesn't make any sense what a players types. Just keep playing :)!
	}
}

