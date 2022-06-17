
class Game
{
private:

	void welcome();
	void displayMenu();
	void displayRules();

	void getPlayerInput(std::string& playerInput) const;
	MenuOptions evaluateInput(std::string& playerInput) const;






public:

	void runGame();
};

