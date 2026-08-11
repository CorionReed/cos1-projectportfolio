#pragma once
#include <string>


class Monster
{
private:
	std::string mName;
	int mHp;
	int mMinAttP;
	int mMaxAttP;
	int mDefP;

public:
	Monster();
	Monster(std::string name, int hp, int minAttP, int maxAttP, int defP);

	void setName(std::string name);
	std::string GetName() const;

	void setHp(int hp);
	int GetHp() const;

	void setMinAttP(int minAttP);
	int GetMinAttP() const;

	void setMaxAttP(int maxAttP);
	int GetMaxAttP() const;

	void setDefP(int defP);
	int GetDefP() const;

	int GetRandomAttP() const;
};

