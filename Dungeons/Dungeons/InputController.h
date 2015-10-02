#pragma once
#include "stdafx.h"
#include <string>

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
private:
	void quitGame();
};

