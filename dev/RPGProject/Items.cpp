#include "Items.h"


Items::Items()
{
	iName = "";
	iType = "";
	iAttP = 0;
	iDefP = 0;
}

Items::Items(std::string name, std::string type, int attP, int defP)
{
	iName = name;
	iType = type;
	iAttP = attP;
	iDefP = defP;
}

void Items::setName(std::string name)
{
	iName = name;
}
std::string Items::GetName() const
{
	return iName;
}

void Items::setType(std::string type)
{
	iType = type;
}
std::string Items::GetType() const
{
	return iType;
}

void Items::setAttP(int attP)
{
	iAttP = attP;
}
int Items::GetAttP() const
{
	return iAttP;
}

void Items::setDefP(int defP)
{
	iDefP = defP;
}
int Items::GetDefP() const
{
	return iDefP;
}
