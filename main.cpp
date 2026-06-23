#include <iostream>
#include "include/armor.h"
#include "include/battle.h"
#include "include/exceptions.h"
#include "include/goblin.h"
#include "include/knight.h"
#include "include/monster_loader.h"
#include "include/stats.h"
#include "include/weapon.h"
#include "include/inventory.h"
#include "include/utils.h"
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
    Knight ghost("Spectre", Stats(0, 5), Weapon("Os", 0), Armor("Haine", 0));
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

        Inventory<Weapon> weaponStash;
        weaponStash.addItem(Weapon("Excalibur", 100));
        weaponStash.addItem(Weapon("Arc de lemn", 15));

        Inventory<Armor> armorStash;
        armorStash.addItem(Armor("Scut de Fier", 50));

        std::cout << "--- Verificam inventarele generice (Clasa Template) ---\n";
        weaponStash.showInventory();
        armorStash.showInventory();
        std::cout << "\n";


        Stats s1(200, 25);
        Weapon w1("Sabie de foc", 40);
        Armor a1("Aur", 50);
        Knight karl("Karl", s1, w1, a1);

        Knight copie = karl;
        Knight alt_cavaler("ARthur", Stats(90, 20), Weapon("Pumnal", 5), Armor("Piele", 10));
        alt_cavaler = copie;

        std::cout << karl << "\n";
        std::cout << "Cavaleri creati pana acum: " << Knight::getCreatedCount() << "\n\n";


        std::cout << "--- Verificam functia de Highlight (Functie Template) ---\n";
        printHighlight(karl);
        printHighlight(w1);
        std::cout << "\n";


        auto roster = MonsterLoader::loadFromFile("assets/monsters.txt");
        Battle arena("Pestera", std::move(roster));
        Battle copy_arena = arena;
        (void)copy_arena;

        std::cout << arena << "\n\n";

        while (!arena.finished() && karl.isAlive()) {
            karl.fight(arena);
            arena.runRound(karl);
            arena.advance();
            std::cout << "---\n";
        }

        if (!karl.isAlive()) {
            std::cout << "Karl a cazut in lupta.\n";
        } else {
            std::cout << "Karl a curatat arena de monstri!\n";
        }

        std::cout << "\n--- Incepere Demo-uri de Exceptii ---\n";
        demoInvalidStats();
        demoDeadKnight();

    } catch (const GameException& e) {
        std::cerr << "Eroare de joc: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Eroare neasteptata: " << e.what() << "\n";
        return 2;
    } catch (...) {
        std::cerr << "Eroare total necunoscuta a aparut!\n";
        return 3;
    }

    return 0;
}