#pragma once
class Player
{
public:
 	Player();

	int GetCash();

	void SetCash(int newCash);

	void AddPotToBalance();

	void Bet();

	int GetTotalCards();

	void SetTotalCards(int num);

	void Hit();


private:
	int cash{100};
	int totalCards{}; // this is the value of the cards totaled up
	int pot{};
	bool hasBet = false;

};
