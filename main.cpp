#include <iostream>
#include "include/stats.h"
#include "include/weapon.h"
#include "include/knight.h"

int main() {
    Stats s1(100, 25);
    Weapon w1("Sabie de foc", 15);
    Knight karl("Karl", s1, w1);
    std::cout << karl << std::endl;
    Knight copie= karl;

    return 0;
}