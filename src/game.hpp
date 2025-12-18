#pragma once
enum Winner {PLAYER, DEALER, NONE};
enum GameState {START, PLAYING, END};

class Game
{
public:
	Game();

	void PlayAgain();

	int GetDealerTotalCards();

	void SetDealerTotalCards(int newTotalCards);

	void Deal();
	
	void Stand();

	Winner CheckWinner();
	
	void SetWinner(Winner val);

	GameState CheckGameState();

	void SetGameState(GameState gs);

	bool CanPlayerChoose();

	void SetPlayerChoosing(bool b);

private:
	Winner winner{NONE};
	GameState gameState{START};

// Dealer data will be set here
	int dealerTotalCards {};

	bool canChoose = true; // this says if the player can hit or stand (e.g. if its the dealers turn)

};
