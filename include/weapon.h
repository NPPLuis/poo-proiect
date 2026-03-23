#ifndef OOP_WEAPON_H
#define OOP_WEAPON_H

#include <string>
#include <iostream>

class Weapon {
private:
    std::string name;
    int bonusDamage;

public:
    Weapon(const std::string& name_val, int bonus_val);
    [[nodiscard]] int getBonusDamage() const;
    [[nodiscard]] const std::string& getName() const;
    friend std::ostream& operator<<(std::ostream& os, const Weapon& w);
};

#endif