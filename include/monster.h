#ifndef OOP_MONSTER_H
#define OOP_MONSTER_H


#include <iosfwd>
#include <memory>
#include <string>

class Knight;

class Monster {
private:
    std::string name;
    int hp;
    int damage;

protected:
    virtual void printExtra(std::ostream& os) const;

public:
    Monster(std::string name_val, int hp_val, int damage_val);
    Monster(const Monster&) = default;
    Monster& operator=(const Monster&) = default;
    virtual ~Monster() = default;

    [[nodiscard]] virtual std::unique_ptr<Monster> clone() const = 0;
    virtual void specialAttack(Knight& target) const = 0;

    virtual void attackKnight(Knight& target) const;
    void receiveDamage(int amount);

    [[nodiscard]] int getHp() const;
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] int getDamage() const;
    [[nodiscard]] bool isAlive() const;

    friend std::ostream& operator<<(std::ostream& os, const Monster& m);
};

#endif
