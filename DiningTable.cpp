//
// Created by Alban on 30.03.2025.
//

#include "DiningTable.h"

#include <iostream>
#include <memory>

DiningTable::DiningTable(const int count) {
    ForkCount = count;
    for (int i = 0; i < count; ++i) {
        forks.push_back(std::make_unique<std::binary_semaphore>(1));
    }
}

void DiningTable::TakeForks(int leftIndex, int rightIndex) {
    if (leftIndex == ForkCount - 1) {
        std::swap(leftIndex, rightIndex);
    }
    forks[leftIndex]->acquire();
    forks[rightIndex]->acquire();
}

void DiningTable::PutForks(int leftIndex, int rightIndex) {
    forks[leftIndex]->release();
    forks[rightIndex]->release();
}

int DiningTable::getForksCount() const {
    return ForkCount;
}
