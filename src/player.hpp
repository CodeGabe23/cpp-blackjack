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


private:
	int cash{100};
	int totalCards{}; // this is the value of the cards totaled up
	bool canChoose = true; // this says if the player can hit or stand (e.g. if its the dealers turn)
};
