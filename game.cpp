#include "game.hpp"
#include <iostream>

Game::Game()
{
 	std::cout << "init game\n";
}

Winner Game::CheckWinner()
{
	std::cout << "Checking winner\n";
	return Winner::DEALER;
}

GameState Game::CheckGameState() {return gameState;}

void Game::Deal()
{
 std::cout << "dealing\n";
}
