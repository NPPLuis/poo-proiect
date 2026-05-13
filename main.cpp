#include <iostream>

#include "include/armor.h"
#include "include/battle.h"
#include "include/exceptions.h"
#include "include/goblin.h"
#include "include/knight.h"
#include "include/monster_loader.h"
#include "include/stats.h"
#include "include/weapon.h"

namespace {

void demoInvalidStats() {
    try {
        Stats bad(-10, 5);
        (void)bad;
    } catch (const InvalidStatsException& e) {
        std::cout << "[capturat] " << e.what() << "\n";
    }
}

void demoDeadKnight() {
    Knight ghost("Spectre", Stats(0, 5), Weapon("Os", 0), Armor("Zdrente", 0));
    try {
        Goblin dummy_target("test", 10, 1);
        ghost.attackMonster(dummy_target);
    } catch (const DeadKnightException& e) {
        std::cout << "[capturat] " << e.what() << "\n";
    }
}

}

int main() {
    try {
        Stats s1(200, 25);
        Weapon w1("Sabie de foc", 40);
        Armor a1("Aur", 50);
        Knight karl("Karl", s1, w1, a1);

        Knight copie = karl;
        Knight alt_cavaler("Arthur", Stats(90, 20), Weapon("Pumnal", 5), Armor("Piele", 10));
        alt_cavaler = copie;

        std::cout << karl << "\n";
        std::cout << "Cavaleri creati pana acum: " << Knight::getCreatedCount() << "\n\n";

        auto roster = MonsterLoader::loadFromFile("assets/monsters.txt");
        Battle arena("Pestera", std::move(roster));
        Battle copy_arena = arena;
        (void)copy_arena;

        std::cout << arena << "\n\n";

        while (!arena.finished()) {
            karl.fight(arena);
            arena.runRound(karl);
            arena.advance();
            std::cout << "---\n";
        }

        demoInvalidStats();
        demoDeadKnight();
    } catch (const GameException& e) {
        std::cerr << "Eroare de joc: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Eroare neasteptata: " << e.what() << "\n";
        return 2;
    }

    return 0;
}
