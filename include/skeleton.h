#ifndef OOP_SKELETON_H
#define OOP_SKELETON_H

#include "monster.h"

class Skeleton : public Monster {
private:
    int reviveCharges;

protected:
    void printExtra(std::ostream& os) const override;

public:
    Skeleton(const std::string& name_val, int hp_val, int damage_val, int revives_val);

    [[nodiscard]] std::unique_ptr<Monster> clone() const override;
    void specialAttack(Knight& target) const override;
};

#endif
