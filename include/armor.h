#ifndef OOP_ARMOR_H
#define OOP_ARMOR_H

#include <string>
#include <iostream>

class Armor {
private:
    std::string name;
    int bonusHP;

public:
    Armor(const std::string &name_val, int bonusHP_val);

    [[nodiscard]] int getBonusHP() const;
    [[nodiscard]] const std::string& getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Armor& a);
};

#endif