#include "pch.h"
#include "PlayGame.h"
#include "Player.h"
#include <vector>
#include <iostream>

using namespace std;

void PlayGame::RunLCR()
{
	// Creating Players
	vector<Player> playerVector;
	int totalPlayers = 0;
	cout << "Please enter the number of players that will play in the game. (Make sure the Number is greater than 3.)" << endl;
	cin >> totalPlayers;


	for (int i = 0; i < totalPlayers; ++i)
	{
		string playerName;
		Player player;
		cout << "Enter the name of Player " << i +1 << ": " << endl;
		cin >> playerName;
		player.SetName(playerName);
		playerVector.push_back(player);
	}

	// Test to display Players.
	cout << "\n\n*** Starting Chip Counts ***   " << endl;
	for (int i = 0; i < playerVector.size(); ++i)
	{
		cout << playerVector[i].GetName() << "'s Chip Count: " << playerVector[i].GetChipCount() << endl;
	}
	cout << "   ***   ***   ***   ***   " << endl << endl;





	// Player turn changing chips!!
	int winningPlayers = 3;											// Vairable to keep track of players with more than 0. 1 Starts the game.
	while (winningPlayers > 1)
	{
		
		for (int i = 0; i < playerVector.size(); ++i)
		{
			winningPlayers = 0;										// Resets count of winning players.
			int tempChip;
			int diceCount;
			srand(time(0));

			// Get Dice Count
			diceCount = playerVector[i].GetChipCount();
			if (diceCount > 3)										// To make sure Dice is never more than 3.
			{
				diceCount = 3;
			}
			cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
			cout << endl << playerVector[i].GetName() << " can roll " << diceCount << " dice." << endl;
			cout << "Press Enter twice to Roll your dice!" << endl;			// Pause.
			cin.get();
			cin.ignore();

			// Dice Results.
			for (int n = 0; n < diceCount; ++n)
			{
				int diceResult = rand() % 6 + 1;			// Random number between 1-6 for 6 sided die.


				// SET TO REMOVE: cout << "Dice Result" << diceResult << endl;
				// Switch to do results.
				switch (diceResult)
				{
				case 1:
					cout << "             ___" << endl;
					cout << "Dice shows: | L |" << endl;
					cout << "             --- " << endl;
					playerVector[i].SetChipCount(playerVector[i].GetChipCount() - 1);
					cout << "1 chip Removed from " << playerVector[i].GetName() << endl;
		
					////////////////////////////////////////////////////////////////////////////////////////////
					// Check for which player is giving which player.												// Last to First
					if (i == playerVector.size() - 1)
					{
						cout << "\n Last Player detected. Giving to first." << endl;					// Chip given to First player if Current is last.
						playerVector[0].SetChipCount(playerVector[0].GetChipCount() + 1);
					}
					else
					{
						cout << "\n Chip Given to next player normal" << endl;							// Chip Given to next player.
						playerVector[i + 1].SetChipCount(playerVector[i + 1].GetChipCount() + 1);
					}
					////////////////////////////////////////////////////////////////////////////////////////////////

					cout << "Chip Count " << playerVector[i].GetChipCount() << endl << endl;			// Chip movement done. Display current player chip count.
					break;
				case 2:
					cout << "             ___" << endl;
					cout << "Dice shows: | C |" << endl;
					cout << "             --- " << endl;
					playerVector[i].SetChipCount(playerVector[i].GetChipCount() - 1);
					cout << "1 chip Removed from " << playerVector[i].GetName() << endl;
					cout << "Chip Count " << playerVector[i].GetChipCount() << endl << endl;
					break;
				case 3:
					cout << "             ___" << endl;
					cout << "Dice shows: | R |" << endl;
					cout << "             --- " << endl;
					playerVector[i].SetChipCount(playerVector[i].GetChipCount() - 1);
					cout << "1 chip Removed from " << playerVector[i].GetName() << endl;

					////////////////////////////////////////////////////////////////////////////////////////////////
					if (i == 0)																								// First to Last
					{
						cout << "\n First Player detected. Giving to Last" << endl;
						playerVector[playerVector.size() - 1].SetChipCount(playerVector[playerVector.size() - 1].GetChipCount() + 1);	// Chip given to last player.
					}
					else
					{
						cout << "\n Chip Given to next player normal" << endl;							// Chip Given to Previous player.
						playerVector[i - 1].SetChipCount(playerVector[i - 1].GetChipCount() + 1);
					}
					////////////////////////////////////////////////////////////////////////////////////////////////

					cout << "Chip Count " << playerVector[i].GetChipCount() << endl << endl;
					break;
				case 4:
				case 5:
				case 6:
					cout << "             ___" << endl;
					cout << "Dice shows: | * |" << endl;
					cout << "             --- " << endl;
					cout << "No Chips Removed for this dice. " << playerVector[i].GetName() << endl;
					cout << "Chip Count " << playerVector[i].GetChipCount() << endl << endl;
					break;
				default:
					cout << "No Dice to roll" << endl;
				}

				// Redisplay players and Chip Count.														TEST
				cout << "\n\n*** End of PLAY Chip Counts ***   ***" << endl;
				for (int i = 0; i < playerVector.size(); ++i)
				{
					cout << playerVector[i].GetName() << "'s Chip Count: " << playerVector[i].GetChipCount() << endl;
				}
				cout << "   ***   ***   ***   ***   " << endl << endl;
			}

			// Check Chip count of every player for winner.
			int tempScore;
			for (int i = 0; i < playerVector.size(); ++i)
			{
				tempScore = playerVector[i].GetChipCount();
				if (tempScore > 0)
				{
					winningPlayers = winningPlayers + 1;
				}
			}
			if (winningPlayers < 2)
			{
				break;
			}

		}


		// Redisplay players and Chip Count.
		cout << "\n\n*** End of Round Chip Counts ***   " << endl;
		for (int i = 0; i < playerVector.size(); ++i)
		{
			cout << playerVector[i].GetName() << "'s Chip Count: " << playerVector[i].GetChipCount() << endl;
		}
		cout << "   ***   ***   ***   ***   " << endl << endl;

		
	}

	//Display winning player
	int winnerScore;
	for (int i = 0; i < playerVector.size(); ++i)
	{
		winnerScore = playerVector[i].GetChipCount();
		if (winnerScore > 0)
		{
			cout << "\n********************************" << endl;
			cout << "***  " << playerVector[i].GetName() << " is the WINNER!   ***" << endl;
			cout << "********************************" << endl << endl;
			cout << "Hope you had fun! Returning to the Menu Screen" << endl << endl;
		}
	}
}



/*void PlayGame::RunPlay()
{
	PlayerCreation();
}*/

