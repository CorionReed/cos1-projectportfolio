#include "Monster.h"

Monster::Monster()
{
	mName = "";
	mHp = 0;
	mMinAttP = 0;
	mMaxAttP = 0;
	mDefP = 0;
	mUnlocked = false;

	mWins = 0;
	mLosses = 0;
}

Monster::Monster(std::string name, int hp, int mMinAtt, int mMaxAtt, int mDef, bool unlocked)
{
	mName = name;
	mHp = hp;
	mMinAttP = mMinAtt;
	mMaxAttP = mMaxAtt;
	mDefP = mDef;
	mUnlocked = unlocked;

	mWins = 0;
	mLosses = 0;
}

void Monster::setName(std::string name)
{
	mName = name;
}
std::string Monster::GetName() const
{
	return mName;
}

void Monster::setHp(int hp)
{
	mHp = hp;
}
int Monster::GetHp() const
{
	return mHp;
}

void Monster::setMinAttP(int mMinAtt)
{
	mMinAttP = mMinAtt;
}
int Monster::GetMinAttP() const
{
	return mMinAttP;
}

void Monster::setMaxAttP(int mMaxAtt)
{
	mMaxAttP = mMaxAtt;
}
int Monster::GetMaxAttP() const
{
	return mMaxAttP;
}

void Monster::setDefP(int mDef)
{
	mDefP = mDef;
}
int Monster::GetDefP() const
{
	return mDefP;
}

int Monster::GetRandomAttP() const
{
	if (mMinAttP == mMaxAttP)
	{
		return mMinAttP;
	}
	else
	{
		return rand() % (mMaxAttP - mMinAttP + 1) + mMinAttP;
	}
}

void Monster::AddWin()
{
	mWins++;
}
int Monster:: GetWins() const
{
	return mWins;
}

void Monster::AddLoss()
{
	mLosses++;
}
int Monster::GetLosses() const
{
	return mLosses;
}

void Monster::setUnlocked(bool unlocked)
{
	mUnlocked = unlocked;
}
bool Monster::GetUnlocked()const
{
	return mUnlocked;
}

void Monster::setWins(int wins)
{
	mWins = wins;
}
void Monster::setLosses(int losses)
{
	mLosses = losses;
}
