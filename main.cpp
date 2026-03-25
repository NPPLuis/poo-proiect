#include <iostream>
#include "include/stats.h"
#include "include/weapon.h"
#include "include/knight.h"
#include "include/armor.h"
int main() {
    Stats const s1(100, 25);
    Weapon const w1("Sabie de foc", 15);
    Armor const a1("aur",50);
    Knight const karl("Karl", s1, w1,a1);
    std::cout << karl << std::endl;
    Knight copie= karl;
    std::cout << "Iteme:" << w1.getName() << " , " << a1.getName() << std::endl;
    std::cout << "Atacul total al lui Karl: "<< copie.getTotalAttack() << std::endl;
    return 0;
}