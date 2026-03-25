#include "../include/stats.h"

void Stats::setHp(int new_hp) {
    hp = new_hp;
}

Stats::Stats(int hp_val, int atk_val) : hp(hp_val), attack(atk_val) {}

int Stats::getHp() const { return hp; }

int Stats::getAttack() const { return attack; }

std::ostream& operator<<(std::ostream& os, const Stats& s) {
    os << "HP: " << s.hp << "\nATK: " << s.attack << std::endl;
    return os;
}