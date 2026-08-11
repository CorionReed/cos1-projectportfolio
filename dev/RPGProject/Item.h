#pragma once

#include <string>

class Item
{
	private:
		std::string iName;
		std::string iType;
		int iMinAtt;
		int iMaxAtt;
		int iDefP;

public:
	Item();

	Item(std::string name, std::string type, int minAttP, int maxAttP, int defP);

	void setName(std::string name);
	std::string GetName() const;

	void setType(std::string type);
	std::string GetType() const;

	void setMinAtt(int iMinAtt);
	int GetMinAtt() const;

	void setMaxAtt(int iMaxAttP);
	int GetMaxAtt() const;

	void setDefP(int iDefP);
	int GetDefP() const;


};

