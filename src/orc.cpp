#include "../include/orc.h"
#include "../include/knight.h"
#include <iostream>

Orc::Orc(const std::string& name_val, int hp_val, int damage_val)
    : Monster(name_val, hp_val, damage_val), maxHp(hp_val) {}

std::unique_ptr<Monster> Orc::clone() const {
    return std::make_unique<Orc>(*this);
}

void Orc::specialAttack(Knight& target) const {
    int hit = getDamage();
    if (getHp() * 3 < maxHp) {
        hit = hit + hit / 2;
        std::cout << getName() << " intra in furie! ";
    }
    std::cout << getName() << " loveste cu " << hit << " damage!\n";
    target.receiveDamage(hit);
}

void Orc::printExtra(std::ostream& os) const {
    os << " [Orc]";
}
