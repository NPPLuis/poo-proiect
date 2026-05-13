#include "../include/dragon.h"
#include "../include/knight.h"
#include <iostream>

Dragon::Dragon(const std::string& name_val, int hp_val, int damage_val, int fire_bonus_val)
    : Monster(name_val, hp_val, damage_val), fireBonus(fire_bonus_val) {}

std::unique_ptr<Monster> Dragon::clone() const {
    return std::make_unique<Dragon>(*this);
}

void Dragon::specialAttack(Knight& target) const {
    const int hit = getDamage() + fireBonus;
    std::cout << getName() << " sufla foc si arde pentru " << hit << " damage!\n";
    target.receiveDamage(hit);
}

int Dragon::getFireBonus() const {
    return fireBonus;
}

void Dragon::printExtra(std::ostream& os) const {
    os << " [Dragon, foc +" << fireBonus << "]";
}
