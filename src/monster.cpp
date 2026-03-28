#include "../include/monster.h"
#include "../include/knight.h"
#include <iostream>

Monster::Monster(const std::string& name_val, int hp_val, int damage_val)
    : name(name_val), hp(hp_val), damage(damage_val) {}

void Monster::attackKnight(Knight& target) const {
    std::cout << name << "l-a atacat pe " << target.getName() << " cu " << damage<<" damage!\n";
    target.receiveDamage(damage);
}

void Monster::receiveDamage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
    std::cout << "HP ramas: " << hp << "\n";
}

int Monster::getHp() const { return hp; }

const std::string& Monster::getName() const { return name; }

int Monster::getDamage() const {
    return damage;
}

std::ostream& operator<<(std::ostream& os, const Monster& m) {
    os << "Monstru: " << m.name << " | HP: " << m.hp << " | ATK: " << m.damage;
    return os;
}