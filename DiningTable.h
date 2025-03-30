//
// Created by Alban on 30.03.2025.
//

#ifndef DININGTABLE_H
#define DININGTABLE_H
#include <memory>
#include <mutex>
#include <semaphore>
#include <vector>


class DiningTable {
    std::vector<std::unique_ptr<std::binary_semaphore>> forks;
    std::vector<std::unique_ptr<std::mutex>> mutex;
    int ForkCount;

public:
    explicit DiningTable(int count);
    ~DiningTable() = default;
    // void lockMutex(int index);
    // void unlockMutex(int index);
    [[nodiscard]] int getForksCount () const;
    void TakeForks (int leftIndex, int rightIndex);
    void PutForks (int leftIndex, int rightIndex);
};



#endif //DININGTABLE_H
