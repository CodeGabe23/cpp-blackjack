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

void Game::Deal()
{
 std::cout << "dealing\n";
}
