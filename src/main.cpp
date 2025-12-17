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

	// for rectangle button bounds
	Rectangle dealBounds = {SCREEN_WIDTH / 3 + 50, SCREEN_HEIGHT / 2, 161, 47};
	Rectangle hitBounds = {SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 3, 165, 55};
	Rectangle standBounds = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3,167, 53};

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		// Place BG image
		DrawTexture(bg, 0, 0, WHITE);

		//Draw Players Cash
		DrawText(TextFormat("Cash: $%d", player.GetCash()), 50, 50, 42, GOLD);
		//Draw Dealer stats (current number)
		DrawText(TextFormat("Dealer Cards: %d", game.GetDealerTotalCards()), SCREEN_WIDTH - 250, 50, 28, YELLOW);

		//Draw Player stats (current number and bet)
		DrawText(TextFormat("Player Cards: %d", player.GetTotalCards()), SCREEN_WIDTH - 250, SCREEN_HEIGHT - 100, 28, YELLOW);
		//Check gamestate
		//check where mouse cursor is
		Vector2 mouseCursorPoint = GetMousePosition();

		switch (game.CheckGameState())
		{
			case START:
				//display DEAL button
				DrawTexture(deal, SCREEN_WIDTH / 3 + 50, SCREEN_HEIGHT / 2, WHITE);
				
				// if mouse is hovering over the deal button
				if (CheckCollisionPointRec(mouseCursorPoint, dealBounds))
				{
					// if mouse is clicking deal button
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						std::cout << "CLICKING DEAL BUTTON\n";
						game.Deal();
					}
				}
				// check if the user click the texture
					

				break;
			case PLAYING:
				// Check winner status
				if (game.CheckWinner() == PLAYER) std::cout << "player won";
				else if (game.CheckWinner() == DEALER) std::cout << "CPU dealer won";
				
				// display Hit && Stand buttons
				DrawTexture(hit, SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 3, WHITE);
				DrawTexture(stand, SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 3, WHITE);
				
				// if mouse is hovering over the HIT button
				if (CheckCollisionPointRec(mouseCursorPoint, hitBounds))
				{
					// if mouse is clicking HIT button
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						std::cout << "CLICKING HIT BUTTON\n";
						player.Hit();
					}
				}

				// if mouse is hovering over the Stand button
				if (CheckCollisionPointRec(mouseCursorPoint, standBounds))
				{
					// if mouse is clicking Stand button
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						std::cout << "CLICKING STAND BUTTON\n";
						player.Stand();
					}
				}

				//check player total card value
				if (player.GetTotalCards() > 21)
				{
					// set game enum winner to dealer
					game.SetWinner(DEALER);
					game.SetGameState(END);
				}
				else if (player.GetTotalCards() == 21)
				{
					DrawText("You got Blackjack!", SCREEN_WIDTH / 2 - 100, 300, 50, YELLOW);
				}

				break;
			case END:
				//display play again button and statistics buttons
				std::cout << "its the end of the game\n";
				if (game.CheckWinner() == PLAYER)
				{	
					DrawText("YOU LOST!", SCREEN_WIDTH / 2 - 100, 300, 50, RED);
				}
				else 
				{
					DrawText("YOU WON!", SCREEN_WIDTH / 2 - 100, 300, 50, GREEN);
				}
				DrawTexture(play_again, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 50, WHITE);

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
