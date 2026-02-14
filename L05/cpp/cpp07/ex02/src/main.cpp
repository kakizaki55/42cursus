#include <iostream>
#include <string>
#include "../include/Array.hpp"

#define MAX_VAL 750

int main(void)
{
    std::cout << "=== Test 1: Default constructor (empty array) ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    std::cout << "\n=== Test 2: Parameterized constructor ===" << std::endl;
    Array<int> numbers(5);
    std::cout << "Array size: " << numbers.size() << std::endl;
    std::cout << "Default values: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Modify elements ===" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    std::cout << "Modified values: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 4: Copy constructor (deep copy) ===" << std::endl;
    Array<int> copy(numbers);
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Copy values: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    // Modify original, copy should NOT change
    numbers[0] = 999;
    std::cout << "After modifying original[0] to 999:" << std::endl;
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << " (should still be 0)" << std::endl;

    std::cout << "\n=== Test 5: Assignment operator (deep copy) ===" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned size: " << assigned.size() << std::endl;

    // Modify assigned, original should NOT change
    assigned[1] = 888;
    std::cout << "After modifying assigned[1] to 888:" << std::endl;
    std::cout << "Assigned[1]: " << assigned[1] << std::endl;
    std::cout << "Original[1]: " << numbers[1] << " (should still be 10)" << std::endl;

    std::cout << "\n=== Test 6: Out of bounds exception ===" << std::endl;
    try
    {
        std::cout << "Trying to access index 100 on array of size 5..." << std::endl;
        numbers[100] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught! Access denied." << std::endl;
    }

    try
    {
        std::cout << "Trying to access empty array..." << std::endl;
        empty[0] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught! Access denied." << std::endl;
    }

    std::cout << "\n=== Test 7: Array of strings ===" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "42";
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << strings[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 8: Large array test ===" << std::endl;
    Array<int> large(MAX_VAL);
    for (int i = 0; i < MAX_VAL; i++)
        large[i] = i;

    Array<int> largeCopy(large);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (large[i] != largeCopy[i])
        {
            std::cout << "Copy failed!" << std::endl;
            return 1;
        }
    }
    std::cout << "Large array copy test passed! (" << MAX_VAL << " elements)" << std::endl;

    // Verify independence
    large[0] = -1;
    if (largeCopy[0] == -1)
    {
        std::cout << "Deep copy failed - arrays are linked!" << std::endl;
        return 1;
    }
    std::cout << "Deep copy independence verified!" << std::endl;

    std::cout << "\n=== Test 9: Const array access ===" << std::endl;
    const Array<int> constArr(numbers);
    std::cout << "Const array[0]: " << constArr[0] << std::endl;
    std::cout << "Const array size: " << constArr.size() << std::endl;

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}
