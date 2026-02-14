#include "../include/Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {

	std::cout << "=== Testing Serializer ===" << std::endl << std::endl;

	// Test 1: Basic serialization and deserialization
	std::cout << "Test 1: Basic serialization/deserialization" << std::endl;
	Data* original = new Data;
	original->setValue(42);

	std::cout << "Original Data address: " << original << std::endl;
	std::cout << "Original Data value: " << original->getValue() << std::endl;

	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized to uintptr_t: " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << deserialized << std::endl;
	std::cout << "Deserialized Data value: " << deserialized->getValue() << std::endl;

	if (original == deserialized && original->getValue() == deserialized->getValue()) {
		std::cout << "Test 1 PASSED: Pointers match and values are preserved" << std::endl;
	} else {
		std::cout << "Test 1 FAILED" << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Multiple different Data objects
	std::cout << "Test 2: Multiple Data objects" << std::endl;
	Data* data1 = new Data;
	Data* data2 = new Data;
	data1->setValue(100);
	data2->setValue(200);

	uintptr_t raw1 = Serializer::serialize(data1);
	uintptr_t raw2 = Serializer::serialize(data2);

	Data* result1 = Serializer::deserialize(raw1);
	Data* result2 = Serializer::deserialize(raw2);

	if (data1 == result1 && data2 == result2 &&
		data1->getValue() == 100 && data2->getValue() == 200) {
		std::cout << "Test 2 PASSED: Multiple objects handled correctly" << std::endl;
	} else {
		std::cout << "Test 2 FAILED" << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Null pointer handling
	std::cout << "Test 3: Null pointer" << std::endl;
	Data* nullData = NULL;
	uintptr_t rawNull = Serializer::serialize(nullData);
	Data* resultNull = Serializer::deserialize(rawNull);

	if (resultNull == NULL) {
		std::cout << "Test 3 PASSED: Null pointer preserved" << std::endl;
	} else {
		std::cout << "Test 3 FAILED" << std::endl;
	}
	std::cout << std::endl;

	// Cleanup
	delete original;
	delete data1;
	delete data2;

	return 0;
}