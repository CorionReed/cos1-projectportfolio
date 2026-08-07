#include "Item.h"


Item::Item()
{
	iName = "";
	iType = "";
	iAttP = 0;
	iDefP = 0;
}

Item::Item(std::string name, std::string type, int attP, int defP)
{
	iName = name;
	iType = type;
	iAttP = attP;
	iDefP = defP;
}

void Item::setName(std::string name)
{
	iName = name;
}
std::string Item::GetName() const
{
	return iName;
}

void Item::setType(std::string type)
{
	iType = type;
}
std::string Item::GetType() const
{
	return iType;
}

void Item::setAttP(int attP)
{
	iAttP = attP;
}
int Item::GetAttP() const
{
	return iAttP;
}

void Item::setDefP(int defP)
{
	iDefP = defP;
}
int Item::GetDefP() const
{
	return iDefP;
}
