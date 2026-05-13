#ifndef OOP_DRAGON_H
#define OOP_DRAGON_H

#include "monster.h"

class Dragon : public Monster {
private:
    int fireBonus;

protected:
    void printExtra(std::ostream& os) const override;

public:
    Dragon(const std::string& name_val, int hp_val, int damage_val, int fire_bonus_val);

    [[nodiscard]] std::unique_ptr<Monster> clone() const override;
    void specialAttack(Knight& target) const override;

    [[nodiscard]] int getFireBonus() const;
};

#endif
