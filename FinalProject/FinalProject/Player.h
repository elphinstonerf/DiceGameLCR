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
	void SetName(const string& name)
	{
		playerName = name;
	}

	void SetChipCount(const int& count)
	{
		chipCount = count;
	}

	// Getters.
	const string GetName() const
	{
		return playerName;
	}
	const int& GetChipCount() const
	{
		return chipCount;
	}
};
