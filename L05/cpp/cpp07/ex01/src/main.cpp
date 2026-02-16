#include <iostream>
#include <string>
#include "../include/iter.hpp"


int main(void)
{
    std::cout << "=== Test with int array ===" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original: ";
    ::iter(intArr, intLen, print<int>);
    std::cout << std::endl;

    ::iter(intArr, intLen, increment<int>);
    std::cout << "After increment: ";
    ::iter(intArr, intLen, print<int>);
    std::cout << std::endl;

    ::iter(intArr, intLen, doubleValue<int>);
    std::cout << "After double: ";
    ::iter(intArr, intLen, print<int>);
    std::cout << std::endl;

    std::cout << "\n=== Test with string array ===" << std::endl;
    std::string strArr[] = {"Hello", "World", "42"};
    size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "Strings: ";
    ::iter(strArr, strLen, print<std::string>);
    std::cout << std::endl;

    std::cout << "\n=== Test with const array ===" << std::endl;
    const int constArr[] = {10, 20, 30};
    size_t constLen = sizeof(constArr) / sizeof(constArr[0]);

    std::cout << "Const array: ";
    ::iter(constArr, constLen, print<int>);
    std::cout << std::endl;

	// ::iter(constArr, constLen, increment<const int>);  // Should not compile (const array)

    std::cout << "\n=== Test with double array ===" << std::endl;
    double dblArr[] = {1.52, 2.51, 3.54};
    size_t dblLen = sizeof(dblArr) / sizeof(dblArr[0]);

    std::cout << "Original: ";
    ::iter(dblArr, dblLen, print<double>);
    std::cout << std::endl;

    ::iter(dblArr, dblLen, doubleValue<double>);
    std::cout << "After double: ";
    ::iter(dblArr, dblLen, print<double>);
    std::cout << std::endl;

    return 0;
}
