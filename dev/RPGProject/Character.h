#pragma once
#include <string>
#include <vector>
#include "Item.h"



class Character
{
private:
	std::string cName;
	int cHp;
	int cAttP;
	int cDefP;
	bool cUnlocked;
	
	int cWins;
	int cLosses;

	Item cWeapon;
	Item cArmor;

public:
	Character();

	Character(std::string name, int hp, int attP, int defP, bool unlocked, const Item& weapon, const Item& armor);

	void setName(std::string name);
	std::string GetName() const;

	void setHp(int hp);
	int GetHp() const;

	void setAttP(int attP);
	int GetAttP() const;

	void setDefP(int defP);
	int GetDefP() const;

	void setUnlocked(bool unlocked);
	bool GetUnlocked() const;

	void setWeapon(const Item& weapon);
	Item GetWeapon() const;

	void setArmor(const Item& armor);
	Item GetArmor() const;

	int CalculateTotalAttP() const;
	int CalculateTotalDefP() const;

	void AddWin();
	int GetWins() const;

	void AddLoss();
	int GetLosses()const;

	void setWins(int wins);
	void setLosses(int losses);



	
};

