#pragma once
#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include <vector>

class Game
{

private:
	std::vector<Item> weapons;
	std::vector<Item> armors;
	std::vector<Monster> monsters;
	std::vector<Character> characters;

public:
	Game();

	bool StartMenu();

	Character& SelectCharacter( std::vector<Character>& characters);

	void UnlockCharacter();

	void SelectWeapon(Character& selectedCharacter, const std::vector<Item>& weapons);

	void  SelectArmor(Character& selectedCharacter, const std::vector<Item>& armors);

	Monster& SelectMonster( std::vector<Monster>& monsters);

	void UnlockMonsters();


	void Battle(Character& selectedCharacter, Monster& selectedMonster);

	int PostBattleMenu();

	void SaveProgress();
	bool LoadProgress();
	void Run();


};

