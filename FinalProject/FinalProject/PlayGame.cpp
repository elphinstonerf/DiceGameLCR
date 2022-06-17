#include "pch.h"
#include "PlayGame.h"
#include "Player.h"
#include <vector>
#include <iostream>

using namespace std;

void PlayGame::runLCR()
{
	// Creating Players
	vector<Player> playerVector;
	int totalPlayers = 0;
	cout << "Please enter the number of players that will play in" 
		<<" the game. (This game must have 3 or more Players.)" << endl;
	cin >> totalPlayers;

	// Loop to validate user input.
	while (cin.fail() || totalPlayers < 3)														
	{
		cout << "That did not work." << endl;
		cout << "The number of Players must be 3 or greater. Try again." << endl;
		cin.clear();
		cin.ignore();
		cin >> totalPlayers;
	}

	// Creation of Players for every iteration. 
	for (int i = 0; i < totalPlayers; ++i)													// Number of iterations based on totalPlayers.
	{
		string playerName;
		Player player;
		cout << "Enter the name of Player " << i +1 << ": " << endl;
		cin >> playerName;
		player.setName(playerName);															// Player name updated.
		playerVector.push_back(player);														// Player added to vector.
	}

	// Display of Chip Counts at the beginning of the Game.
	cout << "\n\n*** Starting Chip Counts ***   " << endl;
	for (int i = 0; i < playerVector.size(); ++i)
	{
		cout << playerVector[i].getName() << "'s Chip Count: " 
			<< playerVector[i].getChipCount() << endl;
	}
	cout << "   ***   ***   ***   ***   " << endl << endl;

	// Gameplay of Left Center Right.
	int winningPlayers = 3;																	// Count of players with chips.
	bool quitting = false;
	while (winningPlayers > 1)																// Check for game ending condition.
	{
		
		// Will iterate through all Players simulating turns.
		for (int i = 0; i < playerVector.size(); ++i)
		{
			winningPlayers = 0;																// Resets count winningPlayers.
			int tempChip;
			int diceCount;
			srand(time(0));

			// Get player's dice count.
			diceCount = playerVector[i].getChipCount();
			if (diceCount > 3)																// Dice count must not be greater than 3.
			{
				diceCount = 3;
			}
			cout << "////////////////////////////////////////" 
				<< "//////////////////////////////////////////" << endl;
			cout << endl << playerVector[i].getName() << " can roll " << diceCount << " dice." << endl;

			// Gets player input to continue roll or to quit game.
			int playerInput;
			cout << "Please enter 1 to Roll or 2 to quit." << endl;
			cin >> playerInput;
			while (cin.fail() || playerInput < 0 || playerInput > 2)						// Validates players input.
			{
				cout << "That did not work." << endl;
				cout << "Please enter 1 to Roll or 2 to quit. Try again." << endl;
				cin.clear();
				cin.ignore();
				cin >> playerInput;
			}
			if (playerInput == 1) 
			{						
				cout << "Rolling Dice!" << endl;											// Continues game.
			}
			else
			{
				cout << "Quitting to Main Menu." << endl;
				quitting = true;
				break;																		// Quits and returns to menu.
			}

			// Dice Results.
			for (int n = 0; n < diceCount; ++n)
			{
				int diceResult = rand() % 6 + 1;											// Random number between 1-6 for 6 sided die.

				// Switch to perform action of dice results.
				switch (diceResult)
				{
				case 1:
					// Display specific dice roll result.
					cout << "               ___" << endl;
					cout << "Dice " << n + 1 << " shows: | L |" << endl;					
					cout << "               --- " << endl;
					playerVector[i].setChipCount(playerVector[i].getChipCount() - 1);
					cout << "1 chip Removed from " << playerVector[i].getName() << endl;

					// Statement to ensure chip is added to correct player.												
					if (i == playerVector.size() - 1)										// Chip given to first player if last player.
					{				
						playerVector[0].setChipCount(playerVector[0].getChipCount() + 1);	
					}
					else																	// Chip give to next player.
					{				
						playerVector[i + 1].setChipCount(playerVector[i + 1].getChipCount() + 1);	
					}
					break;
				case 2:
					// Display specific dice roll result.
					cout << "               ___" << endl;
					cout << "Dice " << n + 1 << " shows: | R |" << endl;					
					cout << "               --- " << endl;
					playerVector[i].setChipCount(playerVector[i].getChipCount() - 1);
					cout << "1 chip Removed from " << playerVector[i].getName() << endl;

					// Statement to ensure chip is added to correct player.
					if (i == 0)																// Chip given to last player if first player.									
					{
						playerVector[playerVector.size() - 1].setChipCount(playerVector[playerVector.size() - 1].getChipCount() + 1);	
					}
					else																	// Chip Given to Previous player.
					{						
						playerVector[i - 1].setChipCount(playerVector[i - 1].getChipCount() + 1);	
					}
					break;
				case 3:
					// Display specific dice roll result.
					cout << "               ___" << endl;
					cout << "Dice " << n + 1 << " shows: | C |" << endl;							
					cout << "               --- " << endl;
					playerVector[i].setChipCount(playerVector[i].getChipCount() - 1);
					cout << "1 chip Removed from " << playerVector[i].getName() << endl;
					break;
				case 4:
				case 5:
				case 6:
					// Display specific dice roll result.
					cout << "                ___" << endl;
					cout << "Dice " << n + 1 << " shows : | * | " << endl;							
					cout << "                --- " << endl;
					cout << "No Chips Removed for this dice. " << endl;
					break;
				default:
					cout << "No Dice to roll" << endl;
				}
			}

			// Redisplay players and Chip Count.														
			cout << "\n\n*** End of Player Turn Chip Counts ***   ***" << endl;
			for (int i = 0; i < playerVector.size(); ++i)
			{
				cout << playerVector[i].getName() << "'s Chip Count: " << playerVector[i].getChipCount() << endl;
			}
			cout << "   ***   ***   ***   ***   " << endl << endl;

			// Check Chip count of every player for winner.
			int tempScore;
			for (int i = 0; i < playerVector.size(); ++i)
			{
				tempScore = playerVector[i].getChipCount();
				if (tempScore > 0)
				{
					winningPlayers = winningPlayers + 1;
				}
			}
			if (winningPlayers < 2)															// Check for winning conidtion.
			{
				break;
			}
		}	
	}

	// Checking for quitting conditions.
	if (quitting == false)
	{
		//Display winning player
		int winnerScore;
		for (int i = 0; i < playerVector.size(); ++i)
		{
			winnerScore = playerVector[i].getChipCount();
			if (winnerScore > 0)
			{
				cout << "\n********************************" << endl;
				cout << "***  " << playerVector[i].getName() << " is the WINNER!   ***" << endl;
				cout << "********************************" << endl << endl;
				cout << "Hope you had fun! Returning to the Menu Screen" << endl << endl;
			}
		}
	}
	else
	{
		cout << "Returning to Menu Screen" << endl;											// Player has quit game.
	}
}