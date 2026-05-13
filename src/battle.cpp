#include "../include/battle.h"
#include "../include/dragon.h"
#include "../include/knight.h"

#include <iostream>
#include <utility>

Battle::Battle(std::string arena_name, std::vector<std::unique_ptr<Monster>> roster_val)
    : arenaName(std::move(arena_name)), roster(std::move(roster_val)) {
    if (!roster.empty()) {
        current = roster.front()->clone();
    }
}

Battle::Battle(const Battle& other) : arenaName(other.arenaName) {
    if (other.current) {
        current = other.current->clone();
    }
    roster.reserve(other.roster.size());
    for (const auto& m : other.roster) {
        roster.push_back(m->clone());
    }
}

void swap(Battle& a, Battle& b) noexcept {
    using std::swap;
    swap(a.arenaName, b.arenaName);
    swap(a.current, b.current);
    swap(a.roster, b.roster);
}

Battle& Battle::operator=(Battle other) {
    swap(*this, other);
    return *this;
}

void Battle::advance() {
    if (roster.empty()) {
        current.reset();
        return;
    }
    roster.erase(roster.begin());
    current = roster.empty() ? nullptr : roster.front()->clone();
}

int Battle::dragonSlayerBonus(int base_damage) const {
    if (const auto* dragon = dynamic_cast<const Dragon*>(current.get())) {
        const int bonus = base_damage / 2 + dragon->getFireBonus() / 4;
        std::cout << "Bonus dragon-slayer activ: +" << bonus << " damage\n";
        return base_damage + bonus;
    }
    return base_damage;
}

void Battle::runRound(Knight& hero) const {
    if (!current) return;
    current->specialAttack(hero);
}

bool Battle::finished() const {
    return roster.empty();
}

std::size_t Battle::remaining() const {
    return roster.size();
}

std::ostream& operator<<(std::ostream& os, const Battle& b) {
    os << "Arena: " << b.arenaName << " (" << b.roster.size() << " monstri ramasi)";
    if (b.current) {
        os << "\nInamic curent: " << *b.current;
    }
    return os;
}
