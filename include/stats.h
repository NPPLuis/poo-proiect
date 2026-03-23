#ifndef OOP_STATS_H
#define OOP_STATS_H

#include <iostream>

class Stats {
private:
    int hp;
    int attack;
public:
    Stats(int hp_val, int atk_val);
    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getAttack() const;
    friend std::ostream& operator<<(std::ostream& os, const Stats& s);
};

#endif