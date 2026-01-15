#include "player.hpp"
#include <iostream>
#include <raylib.h>

Player::Player()
{
	std::cout << "init player";
}

int Player::GetCash() 
{
	return cash;
}


void Player::SetCash(int newCash)
{
	cash = newCash;
}

void Player::AddPotToBalance()
{
	cash += (pot * 2);
	pot = 0;
}

void Player::Bet()
{
	cash -= 10;
	pot  += 10;
	hasBet = true;
}
 
int Player::GetTotalCards()
{
	return totalCards;
}

void Player::SetTotalCards(int num)
{
	totalCards = num;
}

void Player::Hit()
{
	totalCards += GetRandomValue(1,11);
}

	
