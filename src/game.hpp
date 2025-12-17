#pragma once
enum Winner {PLAYER, DEALER, NONE};
enum GameState {START, PLAYING, END};

class Game
{
public:
	Game();

	void Deal();

	Winner CheckWinner();

	GameState CheckGameState();
private:
	Winner winner{NONE};
	GameState gameState{START};
};
