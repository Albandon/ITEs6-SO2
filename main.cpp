#include <thread>
#include <vector>

#include "DiningTable.h"
#include "Philosoph.h"

int main(int argc, char* argv[]) {
    int PhilosophsCount = std::stoi(argv[1]);
    if (PhilosophsCount < 2) PhilosophsCount = 5;
    DiningTable table(PhilosophsCount);
    std::vector<std::thread> threads;
    std::vector<Philosoph> Philosophs;

    for (int i = 0; i < PhilosophsCount; i++) {
        Philosophs.emplace_back(i, table);
    }

    for (int i = 0; i < PhilosophsCount; i++) {
        threads.emplace_back(Philosoph::Exist, Philosophs[i]);
    }
    
    for (auto& thread: threads) {
        thread.join();
    }
    return 0;
}
