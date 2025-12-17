#include <raylib.h>
#include <iostream>
#include "game.hpp"
#include "player.hpp"

int main()
{
    Game game;
	Player player;

	InitWindow(850,531, "C++ Blackjack");
	
	// NOTE: textures must be loaded after window init 
	// cuz OpenGL context is requried
	Texture2D bg = LoadTexture("images/bg.jpg");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		// Place BG image
		DrawTexture(bg, 0, 0, WHITE);

		//Draw Players Cash
		DrawText(TextFormat("Cash: $%d", player.GetCash()), 100, 100, 42, GOLD);
		//Draw Dealer stats (current number)
		
		//Draw Player stats (current number and bet)

		// Make Hit && Stand buttons
		EndDrawing();
	}

	// De initialisations
	UnloadTexture(bg);
	
	CloseWindow();

	return 0;
}
