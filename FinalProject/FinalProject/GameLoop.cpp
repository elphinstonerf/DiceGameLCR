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
void Game::welcome()
{
    //cout << "*|*|*|*|* Welcome to Left Center Right: The Dice Game *|*|*|*|*" << endl << endl;

	cout << "          +-+-+-+-++-+-+-+-+-+-++-+-+-+-+-+-+-+" << endl;
	cout << "          |L|E|F|T| |C|E|N|T|E|R| |R|I|G|H|T|:|" << endl;
	cout << "          +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "               |T|h|e| |D|i|c|e| |G|a|m|e|" << endl;
	cout << "               +-+-+-++-+-+-+-++-+-+-+-+-+" << endl;
	cout << "" << endl << endl;
	displayRules();
}

// Main Menu Display
void Game::displayMenu()
{
    cout << "\n**** Main Menu ****     " << endl << endl;
    cout << "Please enter a Number of the option you would like to pick." << endl;
    cout << "1: See the Rules of the game." << endl;
    cout << "2: Play Left Center Right" << endl;
    cout << "3: Quit." << endl;
}

// Display LeftCenterRight_Rules.txt File.
void Game::displayRules()
{
	// Reading from file.
	fstream RuleFile("LeftCenterRight_Rules.txt", ios::in);
	string line;

	if (RuleFile.is_open())														// Check to make sure file exists.
	{
		getline(RuleFile, line);
		while (RuleFile)														// Loop to display all lines of text document.
		{
			cout << line << endl;
			getline(RuleFile, line);
		}
	}
	else
	{
		cout << "File not found." << endl;
	}
	RuleFile.close();															// Make sure file is closed after use.
}

// Get player input.
void Game::getPlayerInput(string& playerInput) const
{
    cin >> playerInput;
}

// Evalue player input
MenuOptions Game::evaluateInput(string& playerInput) const
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
	else																		// User Input Validation.       
	{
		cout << "That is not a Menu option. Please Try Again." << endl << endl; 
	}
	return chosenOption;
}

// Main Game Program
void Game::runGame()
{
    welcome();
    
	bool quitGame = false;
	while (quitGame == false)
	{
		displayMenu();
		
		string playerInput;														// Gets user input for menu selection.
		getPlayerInput(playerInput);

		// Switch for Menu.
		switch (evaluateInput(playerInput))
		{
		case MenuOptions::Rules:
			displayRules();
			cout << "Press any key to continue..." << endl;						// Pause.
			cin.get();
			cin.ignore();
			break;
		case MenuOptions::Play:
			cout << "Starting Game" << endl;
			PlayGame play;											
			play.runLCR();														// Runs LCR Gameplay.
			break;
		case MenuOptions::Quit:
			quitGame = true;
			cout << "Thank you for Playing!" << endl;
			break;
		}
	}
}