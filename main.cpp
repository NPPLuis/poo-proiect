#include <iostream>
#include "include/stats.h"
#include "include/weapon.h"
#include "include/knight.h"

int main() {
    Stats const s1(100, 25);
    Weapon const w1("Sabie de foc", 15);
    Knight const karl("Karl", s1, w1);
    std::cout << karl << std::endl;
    Knight copie= karl;
    std::cout << "DEBUG HP: " << s1.getHp() << std::endl;
    std::cout << "DEBUG Weapon: " << w1.getName() << std::endl;
    std::cout << "Atacul total al lui Karl: " << karl.getTotalAttack() << std::endl;
    return 0;
}