#include "../include/weapon.h"

Weapon::Weapon(const std::string& name_val, int bonus_val)
    : name(name_val), bonusDamage(bonus_val) {}

int Weapon::getBonusDamage() const {
    return bonusDamage;
}

const std::string& Weapon::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Weapon& w) {
    os << "Arma: " << w.name << " (Bonus ATK: +" << w.bonusDamage << ")\n";
    return os;
}