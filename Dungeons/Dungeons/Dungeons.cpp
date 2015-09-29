// Dungeons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string currentAction;

	// Begin beschrijving
	cout << "Welkom bij Roguelike!" << endl;
	cout << "Laten we beginnen! Wat is je naam?" << endl;
	string userName;
	cin >> userName;
	cout << "Welkom " << userName << ". Je bent nu klaar om te beginnen. Als je zover bent, typ dan: !enterDungeon" << endl;
	cin.clear();
	
	cin >> currentAction;
	if (currentAction == "!enterDungeon") {
		cout << "Je komt de eerste ruimte binnen." << endl;
		cout << "Beschrijving: {eerste kamer}" << endl;
	}
	
	while (true) {
		// Keep it alive!
	}
	return 0;
}
