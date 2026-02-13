#include "../include/Data.hpp"

Data::Data() : value(0), name("default") {}

Data::Data(const std::string& name, int value) : value(value), name(name) {}

Data::Data(const Data& other) : value(other.value), name(other.name) {}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		value = other.value;
		name = other.name;
	}
	return *this;
}

Data::~Data() {}

int Data::getValue() const {
	return value;
}

void Data::setValue(int val) {
	value = val;
}

const std::string& Data::getName() const {
	return name;
}

void Data::setName(const std::string& n) {
	name = n;
}