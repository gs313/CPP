#include <iostream>
#include "Array.hpp"

int main (void)
{
    Array<int> intArray(5);
    for (unsigned int i = 0; i < 5; ++i)
        intArray[i] = i * 10;

    std::cout << "Integer Array:" << std::endl;
    for (unsigned int i = 0; i < 5; ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    try {
        std::cout << "Accessing out of bounds index: " << intArray[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // • Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn’t affect the other array.

    Array<int> copiedArray(intArray);
    copiedArray[0] = 100; // Modify the copied array
    std::cout << "Copied Integer Array after modification:" << std::endl;
    for (unsigned int i = 0; i < 5; ++i)
        std::cout << copiedArray[i] << " ";
    std::cout << std::endl;
    std::cout << "Original Integer Array after copy modification:" << std::endl;
    for( unsigned int i = 0; i < 5; ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;
    return 0;
}
