//
// Created by Alban on 30.03.2025.
//

#ifndef PHILOSOPH_H
#define PHILOSOPH_H
#include "DiningTable.h"
#include <chrono>
#include <iostream>
#include <random>

enum PhiloState {
    Thinking = 0,
    Hungry = 1,
    Eating = 2
};

class Philosoph {
    int Id;
    PhiloState State;
    DiningTable &Table;
    int leftFork;
    int rightFork;
public:
    Philosoph(int id, DiningTable &table);
    [[nodiscard]] int getId() const;
    [[nodiscard]] PhiloState getState() const;
    void changeState(PhiloState changeTo);

    void printState() const;

    void Exist();
};
#endif //PHILOSOPH_H
