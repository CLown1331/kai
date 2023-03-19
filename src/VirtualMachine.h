//
// Created by Araf Al Jami on 19/03/2023.
//

#ifndef KAI_VIRTUALMACHINE_H
#define KAI_VIRTUALMACHINE_H

#include <array>

class VirtualMachine {
public:
    VirtualMachine();
    ~VirtualMachine();
    void tick();
    void loadProgram(std::array<int, 1024> program);
    void run();
private:
    std::array<int, 1024> memory;
    std::array<int, 4> registers;
    std::array<int, 1024> stack;
    std::array<int, 1024> heap;
    std::array<int, 1024> program;
    int programCounter;
    int stackPointer;
    int heapPointer;
    bool isRunning;
};


#endif //KAI_VIRTUALMACHINE_H
