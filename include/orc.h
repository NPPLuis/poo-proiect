#ifndef OOP_ORC_H
#define OOP_ORC_H

#include "monster.h"

class Orc : public Monster {
private:
    int maxHp;

protected:
    void printExtra(std::ostream& os) const override;

public:
    Orc(const std::string& name_val, int hp_val, int damage_val);

    [[nodiscard]] std::unique_ptr<Monster> clone() const override;
    void specialAttack(Knight& target) const override;
};

#endif
