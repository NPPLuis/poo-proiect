#ifndef OOP_GOBLIN_H
#define OOP_GOBLIN_H

#include "monster.h"

class Goblin : public Monster {
private:
    int maxHp;

protected:
    void printExtra(std::ostream& os) const override;

public:
    Goblin(const std::string& name_val, int hp_val, int damage_val);
    [[nodiscard]] std::unique_ptr<Monster> clone() const override;
    void specialAttack(Knight& target) const override;
};

#endif
