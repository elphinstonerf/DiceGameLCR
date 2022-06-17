#pragma once

#include <string>

using namespace std;

class Player
{
private:
	string playerName;
	int chipCount = 3;

public:
	Player()
	{
	}

	// Setters.
	void setName(const string& name)
	{
		playerName = name;
	}

	void setChipCount(const int& count)
	{
		chipCount = count;
	}

	// Getters.
	const string getName() const
	{
		return playerName;
	}
	const int& getChipCount() const
	{
		return chipCount;
	}
};
