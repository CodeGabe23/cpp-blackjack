#pragma once
enum Winner {PLAYER, DEALER};

class Game
{
public:
	Game();

	void Deal();

	Winner CheckWinner();
};
