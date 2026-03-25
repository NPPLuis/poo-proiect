#ifndef OOP_MONSTER_H
#define OOP_MONSTER_H


#include <string>

class Knight;

class Monster {
private:
    std::string name;
    int hp;
    int damage;

public:
    explicit Monster(const std::string& name_val, int hp_val, int damage_val);

    void receiveDamage(int amount);
    void attackKnight(Knight& target) const;

    [[nodiscard]] int getHp() const;
    [[nodiscard]] const std::string& getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Monster& m);
};

#endif
