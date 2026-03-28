#include "../include/knight.h"
#include "../include/monster.h"
#include <iostream>

Knight::Knight(const std::string& name_val, const Stats& stats_val, const Weapon& weapon_val, const Armor& armor_val) :
     name(name_val), stats(stats_val), weapon(weapon_val), armor(armor_val) {}

Knight::Knight(const Knight& other)
    : name(other.name), stats(other.stats), weapon(other.weapon), armor(other.armor) {
    std::cout << "S-a creat o clona pentru cavalerul: " << name << std::endl;
}

Knight& Knight::operator=(const Knight& other) {
    if (this != &other) {
        name = other.name;
        stats = other.stats;
        weapon = other.weapon;
        armor = other.armor;
    }
    return *this;
}

Knight::~Knight() {
    std::cout << "Cavalerul " << name << " s-a despwanat" << std::endl;
}

int Knight::getTotalAttack() const {
    return stats.getAttack() + weapon.getBonusDamage();
}
int Knight::getTotalHP() const {
    return stats.getHp()+ armor.getBonusHP();
}

int Knight::getTotalHP() const {
    return stats.getHp() + armor.getBonusHP();
}

const std::string& Knight::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Knight& k) {
    os << "Cavaler: " << k.name << "\n" << k.stats << k.weapon << k.armor;
    os << "Putere totala: " << k.getTotalAttack() << std::endl;
    os << "Viata totala: " << k.getTotalHP() << std::endl;
    return os;
}

void Knight::receiveDamage(int damage_amount) {
    int hp_baza = stats.getHp();
    stats.setHp(hp_baza - damage_amount);
    std::cout << "HP ramas: " << getTotalHP() << std::endl;
}

void Knight::attackMonster(Monster& target) const {
    int damage = this->getTotalAttack();
    std::cout << name << " ataca monstrul cu " << damage << " damage!\n";
    target.receiveDamage(damage);
}