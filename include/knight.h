
#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include <string>
#include "stats.h"
#include "weapon.h"

class Knight {
private:
    std::string name;
    Stats stats;
    Weapon weapon;

public:
    Knight(const std::string& name_val, const Stats& stats_val, const Weapon& weapon_val);
    Knight(const Knight& other);
    Knight& operator=(const Knight& other);
    ~Knight();

    [[nodiscard]] int getTotalAttack() const;

    friend std::ostream& operator<<(std::ostream& os, const Knight& k);
};

#endif