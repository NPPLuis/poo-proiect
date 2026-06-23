#ifndef OOP_UTILS_H
#define OOP_UTILS_H

#include <iostream>

template <typename T>
void printHighlight(const T& object) {
    std::cout << "\n==============================\n";
    std::cout << object; 
    std::cout << "==============================\n";
}

#endif