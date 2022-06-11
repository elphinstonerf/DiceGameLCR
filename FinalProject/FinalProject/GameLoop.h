#pragma once

#include "MenuOptions.h"
#include "Player.h"
#include <string>

class Game
{
private:

	void Welcome();
	void DisplayMenu();
	void DisplayRules();

	void GetPlayerInput(std::string& playerInput) const;
	MenuOptions EvaluateInput(std::string& playerInput) const;






public:

	void RunGame();
};

