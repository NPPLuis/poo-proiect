#ifndef OOP_BATTLE_H
#define OOP_BATTLE_H

#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

#include "monster.h"

class Knight;

class Battle {
private:
    std::string arenaName;
    std::unique_ptr<Monster> current;
    std::vector<std::unique_ptr<Monster>> roster;

public:
    Battle(std::string arena_name, std::vector<std::unique_ptr<Monster>> roster_val);
    Battle(const Battle& other);
    Battle& operator=(Battle other);
    Battle(Battle&&) noexcept = default;
    ~Battle() = default;

    friend void swap(Battle& a, Battle& b) noexcept;

    void advance();
    void runRound(Knight& hero) const;
    [[nodiscard]] int dragonSlayerBonus(int base_damage) const;
    [[nodiscard]] bool finished() const;

    friend std::ostream& operator<<(std::ostream& os, const Battle& b);
};

#endif
