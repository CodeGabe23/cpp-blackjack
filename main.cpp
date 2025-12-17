#include <raylib.h>
#include <iostream>
#include "game.hpp"
#include "player.hpp"

int main()
{
	//inits
    Game game;
	Player player;

	constexpr int SCREEN_WIDTH {850};
	constexpr int SCREEN_HEIGHT {531};

	InitWindow(850,531, "C++ Blackjack");

	// textures/images
	// NOTE: textures must be loaded after window init 
	// cuz OpenGL context is requried
	Texture2D bg = LoadTexture("images/bg.jpg");
	Texture2D deal = LoadTexture("images/deal.png");
	Texture2D hit = LoadTexture("images/hit.png");
	Texture2D play_again = LoadTexture("images/play_again.png");
	Texture2D stand = LoadTexture("images/stand.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		// Place BG image
		DrawTexture(bg, 0, 0, WHITE);

		//Draw Players Cash
		DrawText(TextFormat("Cash: $%d", player.GetCash()), 50, 50, 42, GOLD);
		//Draw Dealer stats (current number)
		
		//Draw Player stats (current number and bet)

		//Check gamestate
		switch (game.CheckGameState())
		{
			case START:
				//display DEAL button
				DrawTexture(deal, SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, WHITE);

				break;
			case PLAYING:
				// display Hit && Stand buttons
				break;
			case END:
				//display play again button and statistics buttons
				break;
			default:
				std::cout << "ERROR: game state checking failed";
		}
		

		EndDrawing();
	}

	// De initialisations
	UnloadTexture(bg);
	UnloadTexture(deal);
	UnloadTexture(hit);
	UnloadTexture(play_again);
	UnloadTexture(stand);
	
	CloseWindow();

	return 0;
}
