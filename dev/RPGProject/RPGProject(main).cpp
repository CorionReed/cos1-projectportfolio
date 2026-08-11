// RPGProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "Character.h"
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
	std::vector<Item> weapons =
	{
		Item("Sword", "Weapon", 8, 10, 0),
		Item("Bow", "Weapon", 8, 12, 0),
		Item("Axe", "Weapon", 12, 15, 0)
	};
	std::vector<Item> armors =
	{
		Item("Helmet", "Armor",0, 0, 5),
		Item("Chestplate", "Armor", 0, 0, 10),
		Item("Leggings", "Armor", 0, 0, 8)
	};

	for (const auto& weapon : weapons)
	{
		std::cout << "Weapon: " << weapon.GetName() << ", Type: " << weapon.GetType()
			<< ", Attack Power: " << weapon.GetMinAtt() << " - " << weapon.GetMaxAtt() << std::endl;
		
	}
	std::cout << std::endl;
	for (const auto& armor : armors)
	{
		std::cout << "Armor: " << armor.GetName() << ", Type: " << armor.GetType()
			<< ", Defense Power: " << armor.GetDefP() << std::endl;
	}
	std::cout << std::endl;

	
	std::vector<Character> characters =
	{
		Character("Lucy", 100, 15, 10, true, weapons[0], armors[1]),
		Character("AZ", 120, 12, 15, true, weapons[1], armors[0]),
		Character("Levy", 80, 18, 8, true, weapons[2], armors[2])
		
	};
	//for (const auto& character : characters)
	//{
	//	std::cout << "Character: " << character.GetName() << ", HP: " << character.GetHp() << ", Attack Power: " << character.GetAttP()
	//		<< ", Defense Power: " << character.GetDefP() << ", Unlocked: " << (character.GetUnlocked() ? "Yes" : "No")
	//		<< ", Weapon: " << character.GetWeapon().GetName() << ", Armor: " << character.GetArmor().GetName()
	//		<< std::endl;
	//}
	std::cout << "Choose your character: \n";

	for (size_t i = 0; i < characters.size(); ++i)
	{
		if (characters[i].GetUnlocked())
		{
			std::cout << i + 1 << ". " << characters[i].GetName() << std::endl;
		}
		
	}
	/*this is the character selection loop*/
	Character selectedCharacter;
	int choice;
	std::cout << "Enter the number of your choice: ";
	std::cin >> choice;
	
	if (choice >= 1 && choice <= characters.size() && characters[choice - 1].GetUnlocked())
	{
		selectedCharacter = characters[choice - 1];
		std::cout << "You selected: " << selectedCharacter.GetName() << std::endl;



	}
	
	else
	{
		std::cout << "Invalid choice. Please select a valid character." << std::endl;
	}

	/*weapon selection loop*/
	std::cout << "Choose your Weapon: \n";
	for (size_t i = 0; i < weapons.size(); ++i)
	{
		std::cout << i + 1 << ". " << ", Attack Power: " << weapons[i].GetMinAtt() << " - " << weapons[i].GetMaxAtt() << std::endl;
	}
	int wChoice;
	std::cout << "Enter the number of your choice: ";
	std::cin >> wChoice;
	if (wChoice >= 1 && wChoice <= weapons.size())
	{
		selectedCharacter.setWeapon(weapons[wChoice - 1]);
		std::cout << "You equipped: " << selectedCharacter.GetWeapon().GetName() << std::endl;
	}
	else
	{
		std::cout << "Invalid choice. Please select a valid weapon." << std::endl;
	}
	/*armor selection loop*/
	std::cout << "Choose your Armor: \n";
	for (size_t i = 0; i < armors.size(); ++i)
	{
		std::cout << i + 1 << ". " << armors[i].GetName() << " Defence Stat: " << armors[i].GetDefP() << std::endl;
	}
	int aChoice;
	std::cout << "Enter the number of your choice: ";
	std::cin >> aChoice;
	if (aChoice >= 1 && aChoice <= armors.size())
	{
		selectedCharacter.setArmor(armors[aChoice - 1]);
		std::cout << "You equipped: " << selectedCharacter.GetArmor().GetName() << std::endl;
	}
	else
	{
		std::cout << "Invalid choice. Please select a valid piece of armor." << std::endl;
	}
	
	return 0;
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
