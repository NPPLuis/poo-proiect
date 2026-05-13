#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include <iosfwd>
#include <string>

#include "armor.h"
#include "stats.h"
#include "weapon.h"

class Monster;
class Battle;

class Knight {
private:
    std::string name;
    Stats stats;
    Weapon weapon;
    Armor armor;

    static int total_created;

public:
    Knight(const std::string& name_val, const Stats& stats_val, const Weapon& weapon_val, const Armor& armor_val);
    Knight(const Knight& other);
    Knight& operator=(const Knight& other);
    ~Knight();

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] int getTotalAttack() const;
    [[nodiscard]] int getTotalHP() const;
    [[nodiscard]] bool isAlive() const;

    static int getCreatedCount();

    void receiveDamage(int damage_amount);
    void attackMonster(Monster& target) const;
    void fight(const Battle& battle);

    friend std::ostream& operator<<(std::ostream& os, const Knight& k);
};

#endif
