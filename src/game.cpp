#include "game.hpp"
#include "player.hpp"
#include <iostream>
#include <raylib.h>

Game::Game()
{
	// not working yet
	// need to reset all values to default
 	std::cout << "init game\n";
	Winner winner = NONE;
	GameState gameState = START;

	int dealerTotalCards = 0;


}

void Game::PlayAgain()
{
	// not working yet
	// need to reset all values to default
 	std::cout << "Playing again\n";

	Winner winner = NONE;
	GameState gameState = START;
	int dealerTotalCards = 0;
}

int Game::GetDealerTotalCards()
{
	return dealerTotalCards; 
}

void Game::SetDealerTotalCards()
{
	// null for now
}

Winner Game::CheckWinner()
{
	// no functionality yet
	return winner;
}

void Game::SetWinner(Winner val)
{
	winner = val;	
}

GameState Game::CheckGameState() {return gameState;}

void Game::SetGameState(GameState gs)
{
	gameState = gs;
}

void Game::Deal()
{
	//change gamestate to PLAYING
	gameState = PLAYING;
}
