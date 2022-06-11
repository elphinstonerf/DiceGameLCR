#include "pch.h"
#include "GameLoop.h"
#include "PlayGame.h"
#include "Player.h"
#include <iostream>

// For File 
#include <fstream>
#include <string>

using namespace std;

// Welcome Message.
void Game::Welcome()
{
    cout << "*|*|*|*|* Welcome to Left Center Right: The Dice Game *|*|*|*|*" << endl << endl;
}

// Menu Display
void Game::DisplayMenu()
{
    cout << "** Menu **     " << endl << endl;
    cout << "Please enter a Number of the option you would like to pick." << endl;
    cout << "1: See the Rules of the game." << endl;
    cout << "2: Play Left Center Right" << endl;
    cout << "3: Quit." << endl;
}

// Display LeftCenterRight_Rules.txt File.
void Game::DisplayRules()
{
	// Reading from file.
	fstream RuleFile("LeftCenterRight_Rules.txt", ios::in);
	string line;

	if (RuleFile.is_open())							// Check to make sure file exists.
	{
		getline(RuleFile, line);
		while (RuleFile)							// Loop to display all lines of text document.
		{
			cout << line << endl;
			getline(RuleFile, line);
		}
	}
	else
	{
		cout << "File not found." << endl;
	}
	RuleFile.close();								// Make sure file is closed after use.
	cout << "\n\nThe file has been displayed and closed.\n";
}

// Get player input.
void Game::GetPlayerInput(string& playerInput) const
{
    cin >> playerInput;
}

// Evalue player input
MenuOptions Game::EvaluateInput(string& playerInput) const
{
    MenuOptions chosenOption = MenuOptions::None;

	if (playerInput.compare("1") == 0)
	{
		cout << "You have chosen to See the Rules." << endl << endl;
		chosenOption = MenuOptions::Rules;
	}
	else if (playerInput.compare("2") == 0)						
	{
		cout << "You are Starting to play Left Center Right" << endl << endl;
		chosenOption = MenuOptions::Play;
	}
	else if (playerInput.compare("3") == 0)
	{
		cout << "You have selected to Quit" << endl << endl;
		chosenOption = MenuOptions::Quit;
	}
	else
	{
		cout << "That is not a Menu option. Please Try Again." << endl << endl;
	}
	return chosenOption;
}

// Create Players






void Game::RunGame()
{
    Welcome();
    
	bool quitGame = false;
	while (quitGame == false)
	{
		DisplayMenu();
		
		string playerInput;
		GetPlayerInput(playerInput);

		// Switch for Menu.
		switch (EvaluateInput(playerInput))
		{
		case MenuOptions::Rules:
			cout << "Displaying Rules" << endl;
			DisplayRules();
			cout << "Press any key to continue..." << endl;			// Pause.
			cin.get();
			cin.ignore();
			break;
		case MenuOptions::Play:
			cout << "Starting Game" << endl;
			PlayGame play;											// Added PlayGame.h & PlayGame.cpp ** As well as some Player.h changes.
			play.RunLCR();
			break;
		case MenuOptions::Quit:
			quitGame = true;
			cout << "Thank you for Playing!" << endl;
			break;
		}

	}

}