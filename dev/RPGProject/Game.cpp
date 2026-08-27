#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>


Game::Game()
{
	weapons =
	{
		Item("none", "Weapon", 0, 0, 0),
		Item("Sword", "Weapon", 8, 10, 0),
		Item("Bow", "Weapon", 8, 12, 0),
		Item("Axe", "Weapon", 12, 15, 0),
		Item("Katana", "Weapon", 17, 18, 0),
		Item("Brass Knuckles", "Weapon", 6, 24, 0)
	};

	armors =
	{
		Item("none", "Armor", 0, 0, 0),
		Item("Helmet", "Armor",0, 0, 5),
		Item("Chestplate", "Armor", 0, 0, 10),
		Item("Leggings", "Armor", 0, 0, 8),
		

	};
	monsters =
	{
		/*Unlocked Monster*/
		Monster("Goblin", 50, 5, 8, 2, true),
		Monster("Orc", 80, 8, 12, 4, true),
		Monster("Dragon", 150, 15, 20, 10, true),

		/*Locked Monster*/
		Monster("Demon", 180, 22, 30, 17, false),
		Monster("Angel", 250, 18, 22, 25, false),
	};
	characters =
	{
		/*UnLocked Characters*/
		Character("Stoyer", 150, 15, 18, true, weapons[0], armors[0]),
		Character("Ken", 130, 17, 15, true, weapons[0], armors[0]),
		Character("Emmy", 120, 20, 10, true, weapons[0], armors[0]),

		/*Locked Characters*/
		Character("Lucy", 220, 25, 10, false, weapons[0], armors[0]),
		Character("Sam", 400, 40, 40, false, weapons[0], armors[0]),

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
		{


			int gameChoice = 0;
			while (gameChoice != 3)
			{
				std::cout << "\n1.	New Game\n";
				std::cout << "\n2.	Load Game\n";
				std::cout << "\n3.	Back\n";
				std::cout << "\n Enter choice: ";
				std::cin >> gameChoice;

				switch (gameChoice)
				{
				case 1:

					/*Starts a new defualt game*/
					return true;

				case 2:
					if (LoadProgress())
					{
						std::cout << "\nGame Loaded SUCCESSFULLY!\n";
						return true;
					}
					else 
					{
						break;
					}

				case 3:
					break;

				default:
					std::cout << "Invalid choice. please try again...\n";
					break;
				}
			}
			break;
		}
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
			std::cout << i + 1 << ". " << characters[i].GetName() << "		Wins: "<< characters[i].GetWins()<< "	|	 "<< "Losses: "<< characters[i].GetLosses()<< std::endl;
		}

	}
	
		int choice;
		
		while(true)
		{
			std::cout << "Enter the number of your choice: ";
			std::cin >> choice;
			if (choice >= 1 && choice <= characters.size() && characters[choice - 1].GetUnlocked())
			{
				
				
				std::cout << "You selected: " << characters[choice - 1].GetName() << std::endl;
				return characters[choice - 1];
			}
			else
			{
				std::cout << "Invalid choice. Please select a valid character." << std::endl;
			}
		} 
		

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
		if (monsters[i].GetUnlocked())
		{
			std::cout << i + 1 << ". " << monsters[i].GetName() << " - Wins: " << monsters[i].GetWins() << "	|	 Losses: " << monsters[i].GetLosses() << std::endl;
		}
	}
	
	int mChoice;
	
	while(true)
	{
		std::cout << "Enter the number of your choice: ";
		std::cin >> mChoice;
		if (mChoice >= 1 && mChoice <= monsters.size() && monsters[mChoice- 1].GetUnlocked())
		{
			
			
			std::cout << "You selected: " << monsters[mChoice - 1].GetName() << std::endl;
			return monsters[mChoice - 1];
		}
		else
		{
			std::cout << "Invalid choice. Please select a valid monster." << std::endl;
		}
	} 
	
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
		std::cout << "4. Save Game\n";
		std::cout << "5. Exit Game\n";
		std::cout << "Enter your choice: ";
		std::cin >> postBattleChoice;
		if (postBattleChoice == 4)
		{
			SaveProgress();
			std::cout << "Your progress has been saved SUCCESSFULLY!\n";
		}

		else if (postBattleChoice >= 1 && postBattleChoice <= 3 || postBattleChoice == 5)
		{
			return postBattleChoice;
		
		}
		else
		{
			std::cout << "Invalid choice. Please select a valid option." << std::endl;
		}
	}
}

void Game::GauntletMode()
{
	Character* selectedCharacter = &SelectCharacter(characters);
	SelectWeapon(*selectedCharacter, weapons);
	SelectArmor(*selectedCharacter, armors);

	int maxPLayerHp = selectedCharacter->GetHp();

	//Save every monster's normal starting HP
	std::vector<int>monsterStartHp;

	for (const Monster& monster : monsters)
	{
		monsterStartHp.push_back(monster.GetHp());
	}

	for (int round = 1; round <= 10; ++round)
	{
		std::cout << "\n-----------------\n";
		std::cout << "GAUNTLET ROUND " << round << "\n";
		std::cout << "\n-----------------\n";

		int monsterIndex;
		/*for the first 6 round it will choose from the first 3 monsters*/
		if (round <= 6)
		{
			monsterIndex = rand() % 3;
		}
		/*for the last 4 rounds it will choose from the last 3 monsters*/
		else
		{
			int startIndex = monsters.size() - 3;
			monsterIndex = startIndex + (rand() % 3);
		}
		/*Restores the selected monster before each round*/
		Monster& selectedMonster = monsters[monsterIndex];

		selectedMonster.setHp(monsterStartHp[monsterIndex]);

		std::cout << "\nYour opponent is: " << selectedMonster.GetName() << std::endl;
		std::cout << "Your current HP: " << selectedCharacter->GetHp() << std::endl;

		Battle(*selectedCharacter, selectedMonster);
		UnlockCharacter();
		UnlockMonsters();

		if (selectedCharacter->GetHp() <= 0)
		{
			std::cout << "\n" << selectedCharacter->GetName() << " has been DEFEATED in Round " << round << "!\n";
			std::cout << "GAME OVER!\n";
			return;
		}

	}
}

void Game::UnlockCharacter()
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
				std::cout<< "\n		*** Character Unlocked! ***\n";
				std::cout << "		Lucy is now Available!";
			}
		}
	}
	 
	
}
void Game::UnlockMonsters()
{
	for (const Character& character : characters)
	{
		if (character.GetName() == "Lucy" && character.GetWins() >= 6)
		{
			for (const Monster& monster : monsters)
			{
				if (monster.GetName() == "Dragon" && monster.GetLosses() >= 6)
				{
					for (Monster& unlockMonster : monsters)
					{
						if (unlockMonster.GetName() == "Demon" && !unlockMonster.GetUnlocked())
						{
							unlockMonster.setUnlocked(true);

							std::cout << "\n		*** New Enemy Unlocked! ***\n";
							std::cout << "	Demon is unlocked!\n";
						}
					}
				}
			}
		}
	}
}
void Game::SaveProgress()
{
	std::ofstream file("saveData.csv");

	if (!file.is_open())
	{
		std::cout << "Could not save game data.\n";
		return;

	}
	for (const Character& character : characters)
	{
		file << "Character," << character.GetName() << "," << character.GetWins() << "," << character.GetLosses() << "," << character.GetUnlocked() << "\n\n";

	}
	for (const Monster& monster : monsters)
	{
		file << "Monster," << monster.GetName() << "," << monster.GetWins() << "," << monster.GetLosses() << "," << monster.GetUnlocked() << "\n";
	}
	file.close();
}
bool Game::LoadProgress()
{
	std::ifstream file("saveData.csv");

	if (!file.is_open())
	{
		std::cout << "\nNo saved game was found.\n";
		return false;
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}

		std::stringstream ss(line);

		std::string type;
		std::string name;
		std::string winsText;
		std::string lossesText;
		std::string unlockedText;

		std::getline(ss, type, ',');
		std::getline(ss, name, ',');
		std::getline(ss, winsText, ',');
		std::getline(ss, lossesText, ',');
		std::getline(ss, unlockedText, ',');

		if (type.empty() || name.empty() || winsText.empty() || lossesText.empty() || unlockedText.empty())
		{
			continue;
		}

		int wins = std::stoi(winsText);
		int losses = std::stoi(lossesText);
		bool unlocked = std::stoi(unlockedText);

		if (type == "Character")
		{
			for (Character& character : characters)
			{
				if (character.GetName() == name)
				{
					character.setWins(wins);
					character.setLosses(losses);
					character.setUnlocked(unlocked);
					break;
				}
			}
		}
		else if(type == "Monster")
		{
			for (Monster& monster : monsters)
			{
				if (monster.GetName() == name)
				{
					monster.setWins(wins);
					monster.setLosses(losses);
					monster.setUnlocked(unlocked);
					break;
				}
			}
		}
	}
	file.close();
	
	return true;
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

		UnlockCharacter();
		UnlockMonsters();

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

		//case 4: //Save Progress
		//	
		//	break;
			
		case 5://Exit
			return;

		}


	}
	
	
}