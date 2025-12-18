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

//
// TODO: ADD BETTING FUNCTIONALITY WITH USER's CASH
//
 
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

	
