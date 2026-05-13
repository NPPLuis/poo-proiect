#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& msg);
};

class InvalidStatsException : public GameException {
public:
    explicit InvalidStatsException(const std::string& msg);
};

class MonsterFileException : public GameException {
public:
    explicit MonsterFileException(const std::string& path, const std::string& reason);
};

class DeadKnightException : public GameException {
public:
    explicit DeadKnightException(const std::string& knight_name);
};

#endif
