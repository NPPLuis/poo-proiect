#include "../include/monster_loader.h"
#include "../include/dragon.h"
#include "../include/exceptions.h"
#include "../include/goblin.h"
#include "../include/orc.h"
#include "../include/skeleton.h"

#include <fstream>
#include <sstream>

std::vector<std::unique_ptr<Monster>> MonsterLoader::loadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        throw MonsterFileException(path, "nu poate fi deschis");
    }

    std::vector<std::unique_ptr<Monster>> result;
    std::string line;
    int line_no = 0;
    while (std::getline(in, line)) {
        ++line_no;
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string type;
        std::string name;
        int hp = 0;
        int dmg = 0;
        if (!(iss >> type >> name >> hp >> dmg)) {
            throw MonsterFileException(path, "linia " + std::to_string(line_no) + " malformata");
        }

        if (type == "goblin") {
            result.push_back(std::make_unique<Goblin>(name, hp, dmg));
        } else if (type == "orc") {
            result.push_back(std::make_unique<Orc>(name, hp, dmg));
        } else if (type == "dragon") {
            int fire = 0;
            if (!(iss >> fire)) {
                throw MonsterFileException(path, "dragon fara bonus de foc la linia " + std::to_string(line_no));
            }
            result.push_back(std::make_unique<Dragon>(name, hp, dmg, fire));
        } else if (type == "skeleton") {
            int revives = 0;
            if (!(iss >> revives)) {
                throw MonsterFileException(path, "skeleton fara numar de reinvieri la linia " + std::to_string(line_no));
            }
            result.push_back(std::make_unique<Skeleton>(name, hp, dmg, revives));
        } else {
            throw MonsterFileException(path, "tip necunoscut '" + type + "' la linia " + std::to_string(line_no));
        }
    }

    if (result.empty()) {
        throw MonsterFileException(path, "fisierul nu contine monstri");
    }
    return result;
}
