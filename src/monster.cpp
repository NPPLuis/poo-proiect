#include "../include/monster.h"
#include "../include/knight.h"
#include <iostream>
#include <utility>

Monster::Monster(std::string name_val, int hp_val, int damage_val)
    : name(std::move(name_val)), hp(hp_val), damage(damage_val) {}

void Monster::attackKnight(Knight& target) const {
    std::cout << name << " l-a atacat pe " << target.getName() << " cu " << damage << " damage!\n";
    target.receiveDamage(damage);
}

void Monster::receiveDamage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
    std::cout << "HP ramas: " << hp << "\n";
}

int Monster::getHp() const { return hp; }

const std::string& Monster::getName() const { return name; }

int Monster::getDamage() const { return damage; }

bool Monster::isAlive() const { return hp > 0; }

void Monster::printExtra(std::ostream& os) const {
    (void)os;
}

std::ostream& operator<<(std::ostream& os, const Monster& m) {
    os << "Monstru: " << m.name << " | HP: " << m.hp << " | ATK: " << m.damage;
    m.printExtra(os);
    return os;
}
