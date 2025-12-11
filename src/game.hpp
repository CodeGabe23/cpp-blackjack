#pragma once
enum Winner {Player, Dealer};

class Game
{
public:
	Game();

	void Deal();

	Winner CheckWinner();
};
