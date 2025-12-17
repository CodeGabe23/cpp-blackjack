#include "game.hpp"
#include "player.hpp"
#include <iostream>
#include <raylib.h>

Game::Game()
{
	// not working yet
	// need to reset all values to default
 	std::cout << "init game\n";
}

Winner Game::CheckWinner()
{
	// no functionality yet
	return Winner::NONE;
}

GameState Game::CheckGameState() {return gameState;}

void Game::Deal()
{
	//change gamestate to PLAYING
	gameState = PLAYING;

	// produce random starting numbers for the player and the DEALER
	//	player.SetTotalCards(GetRandomValue(1,11));
}
