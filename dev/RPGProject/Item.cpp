#include "Item.h"


Item::Item()
{
	iName = "";
	iType = "";
	iMinAtt = 0;
	iMaxAtt = 0;
	iDefP = 0;
}

Item::Item(std::string name, std::string type, int minAtt, int maxAtt, int defP)
{
	iName = name;
	iType = type;
	iMinAtt = minAtt;
	iMaxAtt = maxAtt;
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

void Item::setMinAtt(int minAtt)
{
	iMinAtt = minAtt;
}
int Item::GetMinAtt() const
{
	return iMinAtt;
}

void Item::setMaxAtt(int maxAtt)
{
	iMaxAtt = maxAtt;
}
int Item::GetMaxAtt() const
{
	return iMaxAtt;
}

void Item::setDefP(int defP)
{
	iDefP = defP;
}
int Item::GetDefP() const
{
	return iDefP;
}
