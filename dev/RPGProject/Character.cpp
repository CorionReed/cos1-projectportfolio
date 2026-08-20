#include "Character.h"


Character::Character()
{
	cName = "";
	cHp = 0;
	cAttP = 0;
	cDefP = 0;
	cUnlocked = false;
	cWins = 0;
	cLosses = 0;

}

Character::Character(std::string name, int hp, int attP, int defP, bool unlocked, const Item& weapon, const Item& armor)
{
	cName = name;
	cHp = hp;
	cAttP = attP;
	cDefP = defP;
	cUnlocked = unlocked;
	cWeapon = weapon;
	cArmor = armor;
}

void Character::setName(std::string name)
{
	cName = name;
}
std::string Character::GetName() const
{
	return cName;
}

void Character::setHp(int hp)
{
	cHp = hp;
}
int Character::GetHp() const
{
	return cHp;
}

void Character::setAttP(int attP)
{
	cAttP = attP;
}
int Character::GetAttP() const
{
	return cAttP;
}

void Character::setDefP(int defP)
{
	cDefP = defP;
}
int Character::GetDefP() const
{
	return cDefP;
}

void Character::setUnlocked(bool unlocked)
{
	cUnlocked = unlocked;
}
bool Character::GetUnlocked() const
{
	return cUnlocked;
}

void Character::setWeapon(const Item& weapon)
{
	cWeapon = weapon;
}
Item Character::GetWeapon() const
{
	return cWeapon;
}

void Character::setArmor(const Item& armor)
{
	cArmor = armor;
}
Item Character::GetArmor() const
{
	return cArmor;
}

int Character::CalculateTotalAttP() const
{
	return cAttP + cWeapon.GetMinAtt();
}
int Character::CalculateTotalDefP() const
{
	return cDefP + cArmor.GetDefP();
}

void Character::AddWin()
{
	cWins++;
}
int Character::GetWins() const
{
	return cWins;
}

void Character::AddLoss()
{
	cLosses++;
}
int Character::GetLosses() const
{
	return cLosses;
}