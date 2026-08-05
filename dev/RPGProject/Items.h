#pragma once

#include <string>

class Items
{
	private:
		std::string iName;
		std::string iType;
		int iAttP;
		int iDefP;

public:
	Items();

	Items(std::string name, std::string type, int attP, int defP);

	void setName(std::string name);
	std::string GetName() const;

	void setType(std::string type);
	std::string GetType() const;

	void setAttP(int iAttP);
	int GetAttP() const;

	void setDefP(int iDefP);
	int GetDefP() const;


};

