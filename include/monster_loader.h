#ifndef OOP_MONSTER_LOADER_H
#define OOP_MONSTER_LOADER_H

#include <memory>
#include <string>
#include <vector>

#include "monster.h"

class MonsterLoader {
public:
    static std::vector<std::unique_ptr<Monster>> loadFromFile(const std::string& path);
};

#endif
