#pragma once
enum Winner {PLAYER, DEALER, NONE};
enum GameState {START, PLAYING, END};

class Game
{
public:
	Game();

	int GetDealerTotalCards();

	void SetDealerTotalCards();

	void Deal();

	Winner CheckWinner();

	GameState CheckGameState();
private:
	Winner winner{NONE};
	GameState gameState{START};

// Dealer data will be set here
	int dealerTotalCards {};

};
