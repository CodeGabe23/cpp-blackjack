#pragma once
class Player
{
public:
 	Player();

	int GetCash();

	void SetCash();

	int GetTotalCards();

	void SetTotalCards(int num);

	void Hit();

	void Stand();

private:
	int cash{100};
	int totalCards{}; // this is the value of the cards totaled up
};
