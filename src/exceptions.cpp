#include "../include/exceptions.h"

GameException::GameException(const std::string& msg)
    : std::runtime_error(msg) {}

InvalidStatsException::InvalidStatsException(const std::string& msg)
    : GameException("Stats invalide: " + msg) {}

MonsterFileException::MonsterFileException(const std::string& path, const std::string& reason)
    : GameException("Eroare la fisierul de monstri '" + path + "': " + reason) {}

DeadKnightException::DeadKnightException(const std::string& knight_name)
    : GameException("Cavalerul " + knight_name + " este mort si nu mai poate actiona") {}
