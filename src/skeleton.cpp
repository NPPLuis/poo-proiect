#include "../include/skeleton.h"
#include "../include/knight.h"
#include <iostream>

Skeleton::Skeleton(const std::string& name_val, int hp_val, int damage_val, int revives_val)
    : Monster(name_val, hp_val, damage_val), reviveCharges(revives_val) {}

std::unique_ptr<Monster> Skeleton::clone() const {
    return std::make_unique<Skeleton>(*this);
}

void Skeleton::specialAttack(Knight& target) const {
    const int hit = getDamage();
    std::cout << getName() << " scartaie oasele si loveste cu " << hit << " damage!\n";
    target.receiveDamage(hit);
}

void Skeleton::printExtra(std::ostream& os) const {
    os << " [Skeleton, reinvieri ramase=" << reviveCharges << "]";
}
