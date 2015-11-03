#pragma once
#include "stdafx.h"
#include <string>
//#include "Playingfield.h"
#include "Inventory.h"

class Playingfield;

class InputController
{
public:
	static InputController& Instance() {
		static InputController mInstance;
		return mInstance;
	}
	InputController();
	~InputController();
	void CheckInput();

	void setPlayingField(Playingfield* setPf);
private:
	void quitGame();
	void monsterDetection();

	Playingfield* pf;
	Inventory inventory;
};

