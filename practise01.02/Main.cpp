#include "Enemy.h"
#include "GameObject.h"
#include <iostream>
#include "Input.h"
#include "HealthBar.h"
#include "PlayButton.h"
#include "Player.h"
#include "Score.h"
#include <SDL.h>
#include "SDL_image.h"
#include "SDLText.h"
#include <SDL_ttf.h>
#include "Sprite.h"
#include "Coin.h"
#include <string>
#include "Music.h"
#include "Vector2D.h"
#include "Window.h"


bool isGameRunning = true;
int gamestate = 0;


int main(int argc, char* argv[])
{
	Window window;
	Input input;
	Sprite background;
	Sprite menu;
	Sprite howtoplay;
	Sprite gameover;
	Music music;


	TTF_Init();
	//MUSIC////////////
	Music::Initialize();
	SDLText::Initialize();


	//SCREEN//////////////
	if (!window.Initialize("Darkness", 1600, 1040))
	{
		return 0;
	}

	//OBJECTS IN GAME/////////
	Player player(window);
	player.SetVelocity(5);

	Enemy enemy(window);
	enemy.SetSize(57, 92);

	Coin coin(window);
	coin.SetSize(40, 40);
	coin.SetPosition(2000, 2000);

	HealthBar healthbar(window);

	//BUTTONS///////////////
	PlayButton start(window);
	start.SetState(0);

	PlayButton howto(window);
	howto.SetState(1);
	howto.SetPosition(620, 760);

	PlayButton back(window);
	back.SetState(2);
	back.SetPosition(250, 600);

	PlayButton restart(window);
	restart.SetState(3);
	restart.SetPosition(620, 890);


	//TEXT/////////////////////////
	Score* score = new Score;
	score->SetScore("Coin: " + std::to_string(player.GetCoin()));
	//IMAGES/////////////////////
	background.Load("assets/images/HollowBg.png", window);
	background.SetImageDimension(1, 1, 1600, 1040);
	background.SetSpriteDimension(1600, 1040);


	menu.Load("assets/images/Menu.png", window);
	menu.SetImageDimension(1, 1, 1600, 1040);
	menu.SetSpriteDimension(1600, 1040);

	gameover.Load("assets/images/GameOverBg.png", window);
	gameover.SetImageDimension(1, 1, 1600, 1040);
	gameover.SetSpriteDimension(1600, 1040);

	howtoplay.Load("assets/images/LoreBg.png", window);
	howtoplay.SetImageDimension(1, 1, 1600, 1040);
	howtoplay.SetSpriteDimension(1600, 1040);
	//MUSIC///////////////////////
	music.Load("assets/music/OffLimits.wav");
	music.SetVolume(5);
	music.Play(Music::PlayLoop::PLAY_ENDLESS);



	//MAIN GAME LOOP///////////////
	while (isGameRunning)
	{
		window.Clear();
		input.Update();
		switch (gamestate)
		{
		case 0:
			//START MENU////////////////
			window.Clear();
			menu.Render(0, 0, 0, window);

			start.Render(window);
			howto.Render(window);
			start.Update(input, window);
			howto.Update(input, window);

			//IF YOU CLICK ON THE BUTTON THE GAME STARTS////////////////
			if (input.IsMouseClicked() == true && input.GetMousePosition().x <= 920
				&& input.GetMousePosition().x >= 620 && input.GetMousePosition().y
				<= 720 && input.GetMousePosition().y >= 600)
			{
				gamestate = 1;
			}
			//IF YOU CLICK ON THE BUTTON THE HOW TO PLAY MENU POPS UP////////////////
			if (input.IsMouseClicked() == true && input.GetMousePosition().x <= 920
				&& input.GetMousePosition().x >= 620 && input.GetMousePosition().y <= 880
				&& input.GetMousePosition().y >= 760)
			{
				gamestate = 2;
			}
			window.Present();
			break;

		case 1:
			//GAME SCENE///////////////
			window.Clear();
			background.Render(0, 0, 0, window);

			//RENDERS EVERYTHING ON SCREEN/////////
			player.Render(window);
			enemy.Render(window);
			coin.Render(window);
			healthbar.Render(window);
			score->Render(window);

			//UPDATES/////////////////
			player.Update(input);
			enemy.Update(player, coin);
			healthbar.Update(player);
			coin.Update(player);
			//PRINTS THE SCORE//////////
			score->SetScore("Coin: " + std::to_string(player.GetCoin()));

			//KEEPS THE PLAYER INSIDE THE WINDOW/////////
			if (player.GetPositionX() <= 50) player.SetPositionX(50);
			if (player.GetPositionX() >= 1415) player.SetPositionX(1415);
			if (player.GetPositionY() <= -20) player.SetPositionY(-20);
			if (player.GetPositionY() >= 850) player.SetPositionY(850);

			if (player.GetHealth() == 0)
			{
				gamestate = 3;
			}

			window.Present();
			break;
		case 2:
			window.Clear();
			howtoplay.Render(0, 0, 0, window);
			back.Render(window);
			back.Update(input, window);

			if (input.IsMouseClicked() == true && input.GetMousePosition().x <= 550
				&& input.GetMousePosition().x >= 250 && input.GetMousePosition().y
				<= 720 && input.GetMousePosition().y >= 600)
			{
				gamestate = 0;
			}
			window.Present();
			break;
		case 3:
			//GAME OVER SCENE //////////////////////
			window.Clear();
			//SETS ON SCREEN: GAME OVER, FINAL SCORE, RESTART BUTTON//////
			gameover.Render(0, 0, 0, window);
			restart.Render(window);

			score->Render(window);
			restart.Update(input, window);
			score->SetScore("Coins collected: " + std::to_string(player.GetCoin()));
			//IF YOU CLICK ON THE BUTTON THE GAME RESTARTS//////////////
			if (input.IsMouseClicked() == true && input.GetMousePosition().x <= 920
				&& input.GetMousePosition().x >= 620 && input.GetMousePosition().y
				<= 1010 && input.GetMousePosition().y >= 890)
			{
				player.SetPosition(753, 350);
				player.SetHealth(1000);
				enemy.SetPosition(500, 300);
				gamestate = 0;
			}
			window.Present();
			break;

			if (input.IsWindowClosed() == true)
			{
				isGameRunning = false;
			}
			if (input.GetKeyDown() == SDLK_ESCAPE)
			{
				isGameRunning = false;
			}
			break;
		}
		input.Update();

		if (input.IsWindowClosed())
		{
			isGameRunning = false;
		}
		if (input.GetKeyDown() == SDLK_ESCAPE)
		{
			isGameRunning = false;
		}
	}
	delete score;

	Music::Shutdown();
	SDLText::Shutdown();

	background.Unload();
	window.Shutdown();

	return 0;
}