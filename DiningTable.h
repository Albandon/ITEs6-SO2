//
// Created by Alban on 30.03.2025.
//

#ifndef DININGTABLE_H
#define DININGTABLE_H
#include <memory>
#include <semaphore>
#include <vector>


class DiningTable {
    std::vector<std::unique_ptr<std::binary_semaphore>> forks;
    int ForkCount;

public:
    explicit DiningTable(int count);
    ~DiningTable() = default;
    [[nodiscard]] int getForksCount () const;
    void TakeForks (int leftIndex, int rightIndex);
    void PutForks (int leftIndex, int rightIndex);
};



#endif //DININGTABLE_H
