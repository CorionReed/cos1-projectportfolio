#include "Game.h"
#include <iostream>

Game::Game()
{
	weapons =
	{
		Item("none", "Weapon", 0, 0, 0),
		Item("Sword", "Weapon", 8, 10, 0),
		Item("Bow", "Weapon", 8, 12, 0),
		Item("Axe", "Weapon", 12, 15, 0)
	};

	armors =
	{
		Item("none", "Armor", 0, 0, 0),
		Item("Helmet", "Armor",0, 0, 5),
		Item("Chestplate", "Armor", 0, 0, 10),
		Item("Leggings", "Armor", 0, 0, 8)
	};
	monsters =
	{
		Monster("Goblin", 50, 5, 8, 2),
		Monster("Orc", 80, 8, 12, 4),
		Monster("Dragon", 150, 15, 20, 10)
	};
	characters =
	{
		/*UnLocked Characters*/
		Character("Stoyer", 130, 1000, 18, true, weapons[0], armors[0]),
		Character("Ken", 120, 12, 15, true, weapons[0], armors[0]),
		Character("Emmy", 80, 18, 8, true, weapons[0], armors[0]),

		/*Locked Characters*/
		Character("Lucy", 100, 15, 10, false, weapons[0], armors[0]),
		Character("Sam", 160, 20, 20, false, weapons[0], armors[0]),

	};
}

bool Game::StartMenu()
{
	int startChoice;
	
	while (true)
	{
		std::cout << "====== Welcome to Pandemonium RPG! ======\n";
		std::cout << "1. Start Game\n";
		std::cout << "2. How to Play: \n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> startChoice;
		switch (startChoice)
		{
		case 1:
			return true;
			

		case 2:
			std::cout << "How to Play:\n";
			std::cout << "1. Choose a character from the available options.\n";
			std::cout << "2. Equip your character with a weapon and armor.\n";
			std::cout << "3. Select a monster to fight against.\n";
			std::cout << "4. During your turn, you can choose to attack, check stats, or defend.\n";
			std::cout << "5. The battle continues until either you or the monster is defeated.\n";
			std::cout << "6. After the battle, you can choose to fight again, select a different character, or exit the game.\n";
			break;

		case 3:
			std::cout << "Exiting the game. Thank you for playing!" << std::endl;
			return false;

		default:
			std::cout << "Invalid choice. Please select a valid option." << std::endl;
		}
	} 
	return false;
}

Character& Game::SelectCharacter(std::vector<Character>& characters)
{
	std::cout << "Choose your character: \n";

	for (size_t i = 0; i < characters.size(); ++i)
	{
		if (characters[i].GetUnlocked())
		{
			std::cout << i + 1 << ". " << characters[i].GetName() << std::endl;
		}

	}
	
		int choice;
		bool validChoice = false;
		do
		{
			std::cout << "Enter the number of your choice: ";
			std::cin >> choice;
			if (choice >= 1 && choice <= characters.size() && characters[choice - 1].GetUnlocked())
			{
				
				validChoice = true;
				std::cout << "You selected: " << characters[choice - 1].GetName() << std::endl;
				return characters[choice - 1];
			}
			else
			{
				std::cout << "Invalid choice. Please select a valid character." << std::endl;
			}
		} while (!validChoice);
		

}

void Game::SelectWeapon(Character& selectedCharacter, const std::vector<Item>& weapons)
{
	std::cout << "Choose your Weapon: \n";
	for (size_t i = 0; i < weapons.size(); ++i)
	{
		std::cout << i + 1 << ". " << weapons[i].GetName() << ", Attack Power: " << weapons[i].GetMinAtt() << " - " << weapons[i].GetMaxAtt() << std::endl;
	}
	int wChoice;
	bool validChoice = false;
	do
	{
		std::cout << "Enter the number of your choice: ";
		std::cin >> wChoice;
		if (wChoice >= 1 && wChoice <= weapons.size())
		{
			selectedCharacter.setWeapon(weapons[wChoice - 1]);
			validChoice = true;
			std::cout << "You equipped: " << selectedCharacter.GetWeapon().GetName() << std::endl;
		}
		else
		{
			std::cout << "Invalid choice. Please select a valid weapon." << std::endl;
		}
	} while (!validChoice);
}

void Game::SelectArmor(Character& selectedCharacter, const std::vector<Item>& armors)
{
	std::cout << "Choose your Armor: \n";
	for (size_t i = 0; i < armors.size(); ++i)
	{
		std::cout << i + 1 << ". " << armors[i].GetName() << " Defence Stat: " << armors[i].GetDefP() << std::endl;
	}
	int aChoice;
	bool validChoice = false;
	do
	{
		std::cout << "Enter the number of your choice: ";
		std::cin >> aChoice;
		if (aChoice >= 1 && aChoice <= armors.size())
		{
			selectedCharacter.setArmor(armors[aChoice - 1]);
			validChoice = true;
			std::cout << "You equipped: " << selectedCharacter.GetArmor().GetName() << std::endl;
		}
		else
		{
			std::cout << "Invalid choice. Please select a valid armor." << std::endl;
		}
	} while (!validChoice);
}

Monster& Game::SelectMonster( std::vector<Monster>& monsters)
{
	std::cout << "Choose a monster to fight: \n";
	for (std::size_t i = 0; i < monsters.size(); ++i)
	{
		std::cout << i + 1 << ". " << monsters[i].GetName() << " - Wins: "<< monsters[i].GetWins()<< "	|	 Losses: "<< monsters[i].GetLosses()<< std::endl;
	}
	
	int mChoice;
	bool validChoice = false;
	do
	{
		std::cout << "Enter the number of your choice: ";
		std::cin >> mChoice;
		if (mChoice >= 1 && mChoice <= monsters.size())
		{
			
			validChoice = true;
			std::cout << "You selected: " << monsters[mChoice - 1].GetName() << std::endl;
			return monsters[mChoice - 1];
		}
		else
		{
			std::cout << "Invalid choice. Please select a valid monster." << std::endl;
		}
	} while (!validChoice);
	
}	

void Game::Battle(Character& selectedCharacter, Monster& selectedMonster)
{
	while (selectedCharacter.GetHp() > 0 && selectedMonster.GetHp() > 0)
	{
		int battleChoice;
		bool playerTurnOVer = false;
		bool defending = false;

		

		do
		{

			
			std::cout << "\nYour Turn: \n";
			std::cout << "1. Attack\n";
			std::cout << "2. Check Stats\n";
			std::cout << "3. Defend\n";
			std::cout << "Enter your choice: ";
			std::cin >> battleChoice;

			switch (battleChoice)
			{
			case 1: // Attack
			{
				/*Damage calculation and display*/
				int weaponDam = selectedCharacter.GetWeapon().GetRandomAttP();
				int playerDam = selectedCharacter.GetAttP() + weaponDam;
				int dealtDam = playerDam - selectedMonster.GetDefP();

				if (dealtDam < 0)
				{
					dealtDam = 0;
				}
				selectedMonster.setHp(selectedMonster.GetHp() - dealtDam);
				if (selectedMonster.GetHp() < 0)
				{
					selectedMonster.setHp(0);
				}
				std::cout << "You dealt " << dealtDam << " damage to the " << selectedMonster.GetName() << ". Remaining HP: " << selectedMonster.GetHp() << std::endl;

				playerTurnOVer = true;
				break;
			}

			case 2: // Check Stats

				std::cout << "Character: " << selectedCharacter.GetName() << ", HP: " << selectedCharacter.GetHp() << ", Attack Power: " << selectedCharacter.CalculateTotalAttP()
					<< ", Defense Power: " << selectedCharacter.CalculateTotalDefP() << ", Weapon: " << selectedCharacter.GetWeapon().GetName()
					<< ", Armor: " << selectedCharacter.GetArmor().GetName() << "\n"<< std::endl;

				std::cout << selectedCharacter.GetName() << " - Wins: " << selectedCharacter.GetWins() << "		|	" << "Losses: " << selectedCharacter.GetLosses() << "\n" << std::endl;
				
				break;

			case 3: // Defend 

				defending = true;
				playerTurnOVer = true;

				std::cout << "You brace yourself for the next attack, increasing your defense!" << std::endl;


				break;

			default:

				std::cout << "Invalid choice. Please select a valid option." << std::endl;
				break;

			}
		} while (!playerTurnOVer);
		if (selectedMonster.GetHp() <= 0)
		{
			selectedCharacter.AddWin();
			selectedMonster.AddLoss();
			std::cout << "You defeated the " << selectedMonster.GetName() << "!" << std::endl;
			
			break;

		}
		int monsterDam = selectedMonster.GetRandomAttP();
		int playerDef = selectedCharacter.CalculateTotalDefP();
		if (defending)
		{
			playerDef *= 2; // Double the defense if defending
			defending = false; // Reset defending status for next turn
		}
		int takenDam = (monsterDam * 2) - (playerDef / 2);
		if (takenDam < 0)
		{
			takenDam = 0;
		}
		selectedCharacter.setHp(selectedCharacter.GetHp() - takenDam);
		if (selectedCharacter.GetHp() < 0)
		{
			selectedCharacter.setHp(0);
		}
		std::cout << "The " << selectedMonster.GetName() << " dealt " << takenDam << " damage to you. Remaining HP: " << selectedCharacter.GetHp() << std::endl;
		if (selectedCharacter.GetHp() <= 0)
		{
			selectedCharacter.AddLoss();
			selectedMonster.AddWin();
			std::cout << "You were defeated by the " << selectedMonster.GetName() << "." << std::endl;
			break;
		}
	}
}

int Game::PostBattleMenu()
{
	int postBattleChoice;
	while (true)
	{
		std::cout << "\nBattle Over! What would you like to do next?\n";
		std::cout << "1. Fight Again\n";
		std::cout << "2. Choose a Different Character\n";
		std::cout << "3. Choose a Different Monster\n";
		std::cout << "4. Exit Game\n";
		std::cout << "Enter your choice: ";
		std::cin >> postBattleChoice;
		if (postBattleChoice >= 1 && postBattleChoice <= 4)
		{
			return postBattleChoice;
		
		}
		else
		{
			std::cout << "Invalid choice. Please select a valid option." << std::endl;
		}
	}
}

void Game::UnclockCharacter()
{
	int requiredMonDefeated = 0;
	for (const Monster& monster : monsters)
	{
		if ((monster.GetName() == "Goblin" || "Orc" || "Dragon") && monster.GetLosses() >= 3)
		{
			requiredMonDefeated++;

		}

	}
	if (requiredMonDefeated == 3)
	{
		for (Character& character : characters)
		{
			if (character.GetName() == "Lucy" && !character.GetUnlocked())
			{
				character.setUnlocked(true);
				std::cout<< "\n		*** Character Unlocked!***\n";
				std::cout << "		Lucy is now Available!";
			}
		}
	}
	 
	
}

void Game::Run()
{
	Character* selectedCharacter = &SelectCharacter(characters);
	SelectWeapon(*selectedCharacter, weapons);
	SelectArmor(*selectedCharacter, armors);

	Monster* selectedMonster = &SelectMonster(monsters);

	int playerStartHp = selectedCharacter->GetHp();
	int monsterStartHp = selectedMonster->GetHp();

	while (true)
	{
		selectedCharacter->setHp(playerStartHp);
		selectedMonster->setHp(monsterStartHp);

		Battle(*selectedCharacter, *selectedMonster);

		UnclockCharacter();

		selectedCharacter->setHp(playerStartHp);
		selectedMonster->setHp(monsterStartHp);

		int postBattleChoice = PostBattleMenu();
		switch (postBattleChoice)
		{
		case 1: //Rematch
			
			break;

		case 2: //Different character, same monster.
			selectedCharacter = &SelectCharacter(characters);
			SelectWeapon(*selectedCharacter, weapons);
			SelectArmor(*selectedCharacter, armors);
			selectedCharacter->setHp(playerStartHp);
			
			

			
			break;

		case 3: //Same character, Different monster.

			selectedMonster = &SelectMonster(monsters);
			
			selectedMonster->setHp(monsterStartHp);

			
			break;

		case 4: //Exit
			return;

		}


	}
	
	
}