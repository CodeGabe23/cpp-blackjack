#include "game.hpp"
#include "player.hpp"
#include <iostream>
#include <raylib.h>
#include <type_traits>

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

void Game::SetDealerTotalCards(int newTotalCards)
{
	dealerTotalCards = newTotalCards;
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

GameState Game::CheckGameState() 
{
	return gameState;
}

void Game::SetGameState(GameState gs)
{
	gameState = gs;
}

void Game::Deal()
{
	//change gamestate to PLAYING
	gameState = PLAYING;
}

bool Game::CanPlayerChoose()
{
	return canChoose;
}

void Game::SetPlayerChoosing(bool b)
{
	canChoose = b;
}

void Game::Stand()
{
	// Allow the dealer 4 HITS of cards
	SetDealerTotalCards(GetDealerTotalCards() + GetRandomValue(1,11));
	SetDealerTotalCards(GetDealerTotalCards() + GetRandomValue(1,11));
	SetDealerTotalCards(GetDealerTotalCards() + GetRandomValue(1,11));	
	//SetDealerTotalCards(GetDealerTotalCards() + GetRandomValue(1,11));	

	canChoose =	false; // this says if the player can hit or stand (e.g. if its the dealers turn)
}















