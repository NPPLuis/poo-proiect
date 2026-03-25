#include <iostream>
#include "include/stats.h"
#include "include/weapon.h"
#include "include/armor.h"
#include "include/knight.h"
#include "include/monster.h"

int main() {
    Stats s1(100, 25);
    Weapon w1("Sabie de foc", 15);
    Armor a1("Aur", 50);

    Knight karl("Karl", s1, w1, a1);
    Monster goblin("Goblin Furios", 80, 20);

    Knight copie = karl;
    Knight alt_cavaler("Arthur", Stats(90, 20), Weapon("Pumnal", 5), Armor("Piele", 10));
    alt_cavaler = copie;

    std::cout << karl << "\n";
    std::cout << goblin << "\n";

    karl.attackMonster(goblin);
    goblin.attackKnight(karl);

    s1.setHp(150);
    std::cout << "Stats: HP " << s1.getHp() << " | ATK " << s1.getAttack() << "\n";
    std::cout << "Arma: " << w1.getName() << " | Bonus DMG +" << w1.getBonusDamage() << "\n";
    std::cout << "Armura: " << a1.getName() << " | Bonus HP +" << a1.getBonusHP() << "\n";
    std::cout << "Cavaler Nume: " << karl.getName() << "\n";

    std::cout << "Monstru: " << goblin.getName() << " | HP Ramas: " << goblin.getHp() << "\n";

    return 0;
}