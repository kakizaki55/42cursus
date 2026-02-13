#pragma once
#include <string>

class Data
{

private:
	int value;
	std::string name;

public:
	Data();
	Data(const std::string& name, int value);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();

	const std::string& getName() const;
	int getValue() const;
	void setName(const std::string& name);
	void setValue(int value);
};
