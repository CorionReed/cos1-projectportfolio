// RPGProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Items.h"
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
	std::vector<Items> weapons =
	{
		Items("Sword", "Weapon", 10, 0),
		Items("Bow", "Weapon", 8, 0),
		Items("Axe", "Weapon", 12, 0)
	};
	std::vector<Items> armors =
	{
		Items("Helmet", "Armor", 0, 5),
		Items("Chestplate", "Armor", 0, 10),
		Items("Leggings", "Armor", 0, 8)
	};

	for (const auto& weapon : weapons)
	{
		std::cout << "Weapon: " << weapon.GetName() << ", Type: " << weapon.GetType()
			<< ", Attack Power: " << weapon.GetAttP() << ", Defense Power: " << weapon.GetDefP() << std::endl;
	}
	for (const auto& armor : armors)
	{
		std::cout << "Armor: " << armor.GetName() << ", Type: " << armor.GetType()
			<< ", Attack Power: " << armor.GetAttP() << ", Defense Power: " << armor.GetDefP() << std::endl;
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
