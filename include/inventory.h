#ifndef OOP_INVENTORY_H
#define OOP_INVENTORY_H

#include <vector>
#include <iostream>

template <typename T>
class Inventory {
private:
    std::vector<T> items;

public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    void showInventory() const {
        std::cout << "--- Rucsac (" << items.size() << " obiecte) ---\n";
        for (const auto& item : items) {
            std::cout << item;
        }
        std::cout << "------------------------------\n";
    }
};

#endif