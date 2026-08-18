// RPGProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "Character.h"
#include <vector>
#include "Monster.h"

int main()
{
    
	//vectors for weapons, armors, monsters and characters
	std::vector<Item> weapons =
	{
		Item("none", "Weapon", 0, 0, 0),
		Item("Sword", "Weapon", 8, 10, 0),
		Item("Bow", "Weapon", 8, 12, 0),
		Item("Axe", "Weapon", 12, 15, 0)
	};
	std::vector<Item> armors =
	{
		Item("none", "Armor", 0, 0, 0),
		Item("Helmet", "Armor",0, 0, 5),
		Item("Chestplate", "Armor", 0, 0, 10),
		Item("Leggings", "Armor", 0, 0, 8)
	};
	std::vector<Monster> monsters =
	{
		Monster("Goblin", 50, 5, 8, 2),
		Monster("Orc", 80, 8, 12, 4),
		Monster("Dragon", 150, 15, 20, 10)
	};
	std::vector<Character> characters =
	{
		Character("Lucy", 100, 15, 10, true, weapons[0], armors[0]),
		Character("AZ", 120, 12, 15, true, weapons[0], armors[0]),
		Character("Levy", 80, 18, 8, true, weapons[0], armors[0])

	};

	//for (const auto& weapon : weapons)
	//{
	//	std::cout << "Weapon: " << weapon.GetName() << ", Type: " << weapon.GetType()
	//		<< ", Attack Power: " << weapon.GetMinAtt() << " - " << weapon.GetMaxAtt() << std::endl;
	//	
	//}
	//std::cout << std::endl;
	//for (const auto& armor : armors)
	//{
	//	std::cout << "Armor: " << armor.GetName() << ", Type: " << armor.GetType()
	//		<< ", Defense Power: " << armor.GetDefP() << std::endl;
	//}
	//std::cout << std::endl;
	//for (const auto& monster : monsters)
	//{
	//	std::cout << "Monster: " << monster.GetName() << ", HP: " << monster.GetHp()
	//		<< ", Attack Power: " << monster.GetMinAttP() << " - " << monster.GetMaxAttP()
	//		<< ", Defense Power: " << monster.GetDefP() << std::endl;
	//}
	//std::cout << std::endl;
	//for (const auto& character : characters)
	//{
	//	std::cout << "Character: " << character.GetName() << ", HP: " << character.GetHp() << ", Attack Power: " << character.GetAttP()
	//		<< ", Defense Power: " << character.GetDefP() << ", Unlocked: " << (character.GetUnlocked() ? "Yes" : "No")
	//		<< ", Weapon: " << character.GetWeapon().GetName() << ", Armor: " << character.GetArmor().GetName()
	//		<< std::endl;
	//}
	//std::cout << std::endl;
	int startChoice;
	bool validStartChoice = false;
	do 
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
			validStartChoice = true;
			break;

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
			return 0;
			
		default:
			std::cout << "Invalid choice. Please select a valid option." << std::endl;
		}
	} while (!validStartChoice);
	
	bool chooseAnotherCharacter = false;
	do
	{
		std::cout << "Choose your character: \n";

		for (size_t i = 0; i < characters.size(); ++i)
		{
			if (characters[i].GetUnlocked())
			{
				std::cout << i + 1 << ". " << characters[i].GetName() << std::endl;
			}

		}
		chooseAnotherCharacter = false;
		/*this is the character selection loop*/
		Character selectedCharacter;
		int choice;
		bool validChoice = false;
		do
		{
			std::cout << "Enter the number of your choice: ";
			std::cin >> choice;
			if (choice >= 1 && choice <= characters.size() && characters[choice - 1].GetUnlocked())
			{
				selectedCharacter = characters[choice - 1];
				validChoice = true;
				std::cout << "You selected: " << selectedCharacter.GetName() << std::endl;
			}
			else
			{
				std::cout << "Invalid choice. Please select a valid character." << std::endl;
			}
		} while (!validChoice);

		/*weapon selection loop*/
		std::cout << "Choose your Weapon: \n";
		for (size_t i = 0; i < weapons.size(); ++i)
		{
			std::cout << i + 1 << ". " << weapons[i].GetName() << ", Attack Power: " << weapons[i].GetMinAtt() << " - " << weapons[i].GetMaxAtt() << std::endl;
		}
		int wChoice;
		validChoice = false;
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

		/*armor selection loop*/
		std::cout << "Choose your Armor: \n";
		for (size_t i = 0; i < armors.size(); ++i)
		{
			std::cout << i + 1 << ". " << armors[i].GetName() << " Defence Stat: " << armors[i].GetDefP() << std::endl;
		}
		int aChoice;
		validChoice = false;
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


		int playerStartHp = selectedCharacter.GetHp();
		bool chooseAnotherMonster = false;
		/*monster reselection loop*/
		do
		{
			/*monster selection loop*/

			for (size_t i = 0; i < monsters.size(); ++i)
			{
				std::cout << i + 1 << ". " << monsters[i].GetName() << std::endl;
			}
			Monster selectedMonster;
			int mChoice;
			validChoice = false;
			do
			{
				std::cout << "Choose a monster to fight: ";
				std::cin >> choice;
				if (choice >= 1 && choice <= monsters.size())
				{
					selectedMonster = monsters[choice - 1];
					validChoice = true;
					std::cout << "You selected: " << selectedMonster.GetName() << std::endl;
				}
				else
				{
					std::cout << "Invalid choice. Please select a valid monster." << std::endl;
				}
			} while (!validChoice);
			int monsterStartHp = selectedMonster.GetHp();


			/*Damage calculation and display*/
			int weaponDam = selectedCharacter.GetWeapon().GetRandomAttP();
			int playerDam = selectedCharacter.GetAttP() + weaponDam;

			int dealtDam = playerDam - selectedMonster.GetDefP();
			if (dealtDam < 0)
			{
				dealtDam = 0;
			}

			///*Player att */
			//selectedMonster.setHp(selectedMonster.GetHp() - dealtDam);
			//std::cout << "You dealt " << dealtDam << " damage to the " << selectedMonster.GetName() << ". Remaining HP: " << selectedMonster.GetHp() << std::endl;

			///*Monster att */
			//if (selectedMonster.GetHp() > 0)
			//{
			//	int monsterDam = selectedMonster.GetRandomAttP();
			//	int playerDef = selectedCharacter.CalculateTotalDefP();

			//	

			//	int takenDam = (monsterDam * 2) - (playerDef / 2);
			//	if (takenDam < 0)
			//	{
			//		takenDam = 0;
			//	}
			//	selectedCharacter.setHp(selectedCharacter.GetHp() - takenDam);
			//	std::cout << "The " << selectedMonster.GetName() << " dealt " << takenDam << " damage to you. Remaining HP: " << selectedCharacter.GetHp() << std::endl;
			//}
			//int monsterDam = selectedMonster.GetRandomAttP();
			//int playerDef = selectedCharacter.CalculateTotalDefP();

			//int takenDam = (monsterDam * 2) - (playerDef / 2);
			//if (takenDam < 0)
			//{
			//	takenDam = 0;
			//}
			//selectedCharacter.setHp(selectedCharacter.GetHp() - takenDam);
			//std::cout << "The " << selectedMonster.GetName() << " dealt " << takenDam << " damage to you. Remaining HP: " << selectedCharacter.GetHp() << std::endl;
			//






			bool fightAgain = false;

			do /*play again loop*/
			{
				selectedCharacter.setHp(playerStartHp);

				selectedMonster.setHp(monsterStartHp);

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
								<< ", Armor: " << selectedCharacter.GetArmor().GetName() << std::endl;
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
						std::cout << "You defeated the " << selectedMonster.GetName() << "!" << std::endl;
						break;

					}
					// Player's turn
					//int weaponDam = selectedCharacter.GetWeapon().GetRandomAttP();
					//int playerDam = selectedCharacter.GetAttP() + weaponDam;
					//int dealtDam = playerDam - selectedMonster.GetDefP();
					//if (dealtDam < 0)
					//{
					//	dealtDam = 0;
					//}
					//selectedMonster.setHp(selectedMonster.GetHp() - dealtDam);
					//if (selectedMonster.GetHp() < 0)
					//{
					//	selectedMonster.setHp(0);
					//}
					//std::cout << "You dealt " << dealtDam << " damage to the " << selectedMonster.GetName() << ". Remaining HP: " << selectedMonster.GetHp() << std::endl;
					//if (selectedMonster.GetHp() <= 0)
					//{
					//	std::cout << "You defeated the " << selectedMonster.GetName() << "!" << std::endl;
					//	break;
					//}

					// Monster's turn
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
						std::cout << "You were defeated by the " << selectedMonster.GetName() << "." << std::endl;
						break;
					}
				}
				int postBattleChoice;
				std::cout << "\nBattle Over! What would you like to do next?\n";
				std::cout << "1. Fight Again\n";
				std::cout << "2. Choose a Different Character\n";
				std::cout << "3. Choose a Different Monster\n";
				std::cout << "4. Exit Game\n";
				std::cout << "Enter your choice: ";
				std::cin >> postBattleChoice;

				switch (postBattleChoice)
				{
				case 1:
					std::cout << "Restarting the battle with the same character and monster..." << std::endl;
					fightAgain = true;
					break;

				case 2:
					std::cout << "Returning to character selection..." << std::endl;
					fightAgain = false;
					chooseAnotherMonster = false;
					chooseAnotherCharacter = true;
					
					break;

				case 3:
					std::cout << "Returning to monster selection..." << std::endl;
					fightAgain = false;
					chooseAnotherMonster = true;
					break;

				case 4:
					std::cout << "Exiting the game. Thank you for playing!" << std::endl;

					return 0;

				default:
					std::cout << "Invalid Choice..." << std::endl;
					fightAgain = false;
					break;
				}
			} while (fightAgain);

		} while (chooseAnotherMonster);

	} while (chooseAnotherCharacter);

	

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
