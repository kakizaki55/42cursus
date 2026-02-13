#include "../include/Serializer.hpp"

// Private constructor - class cannot be instantiated
Serializer::Serializer() {}

// Private copy constructor
Serializer::Serializer(const Serializer& other) {
	(void)other;
}

// Private assignment operator
Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

// Destructor
Serializer::~Serializer() {}

// Static method: converts pointer to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

// Static method: converts uintptr_t back to pointer
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}