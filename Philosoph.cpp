//
// Created by Alban on 30.03.2025.
//

#include "Philosoph.h"


Philosoph::Philosoph(const int id, DiningTable &table): Id(id), State(Thinking), Table(table) {
    leftFork = id;
    rightFork = (id+1) % Table.getForksCount();
}

int Philosoph::getId() const {
    return Id;
}

PhiloState Philosoph::getState() const {
    return State;
}

void Philosoph::changeState(PhiloState changeTo) {
    State = changeTo;
    printState();
}

void Philosoph::printState() const {
    std::string stateString;
    switch (State) {
        case Thinking:
            stateString="Thinking";
            break;
        case Hungry:
            stateString="Hungry";
            break;
        case Eating:
            stateString="Eating";
            break;
    }
    
    printf("Philosopher[%d] is %s\n", Id, stateString.c_str());
}

void Philosoph::Exist() {
    std::random_device r;
    std::uniform_int_distribution<int> dist(1000, 3000);
    printState();
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(dist(r)));

        changeState(Hungry);
        
        Table.TakeForks(leftFork, rightFork);
        changeState(Eating);
        std::this_thread::sleep_for(std::chrono::seconds(3));

        Table.PutForks(leftFork, rightFork);
        changeState(Thinking);
    }
}

