
#include "../include/knight.h"
#include <iostream>

Knight::Knight(const std::string& name_val, const Stats& stats_val, const Weapon& weapon_val)
    : name(name_val), stats(stats_val), weapon(weapon_val) {}

Knight::Knight(const Knight& other)
    : name(other.name), stats(other.stats), weapon(other.weapon) {
    std::cout << "S-a creat o clona pentru cavalerul: " << name << std::endl;
}

Knight& Knight::operator=(const Knight& other) {
        name = other.name;
        stats = other.stats;
        weapon = other.weapon;
    return *this;
}

Knight::~Knight() {
    std::cout << "Cavalerul " << name << " a murit" << std::endl;
}

int Knight::getTotalAttack() const {
    return stats.getAttack() + weapon.getBonusDamage();
}

std::ostream& operator<<(std::ostream& os, const Knight& k) {
    os << "Cavaler: " << k.name << "\n" << k.stats << "\n" << k.weapon;
    os << "Putere totala: " << k.getTotalAttack();
    return os;
}