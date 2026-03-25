
#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include <string>
#include "stats.h"
#include "weapon.h"
#include "armor.h"

class Knight {
private:
    std::string name;
    Stats stats;
    Weapon weapon;
    Armor armor;
public:
    Knight(const std::string& name_val, const Stats& stats_val, const Weapon& weapon_val, const Armor& armor_val);
    Knight(const Knight& other);
    Knight& operator=(const Knight& other);
    ~Knight();

    [[nodiscard]] int getTotalAttack() const;
    [[nodiscard]] int getTotalHP() const;
    friend std::ostream& operator<<(std::ostream& os, const Knight& k);
};

#endif