// RPGProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "Character.h"
#include <vector>
#include "Monster.h"
#include "Game.h"

int main()
{
	Game game;
	if (!game.StartMenu())
	{
		return 0; // Exit the game if the player chooses to exit from the start menu
	}
	
	game.Run();

	return 0;
	
	
}




