#pragma once
class Player
{
public:
 	Player();

	int GetCash();

	void Hit();

	void Stand();

	void PresentOptions();
private:
	int cash{100};
};
