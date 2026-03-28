#include "../include/armor.h"
#include<iostream>

Armor::Armor(const std::string& name_val, const int bonusHP_val)
    : name(name_val), bonusHP(bonusHP_val) {}

int Armor::getBonusHP() const {
    return bonusHP;
}

const std::string& Armor::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Armor& a) {
    os << "Armura: " << a.name << " (Aparare: " << a.bonusHP << ")"<<std::endl;
    return os;
}