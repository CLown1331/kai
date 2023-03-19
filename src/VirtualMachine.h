//
// Created by Araf Al Jami on 19/03/2023.
//

#ifndef KAI_VIRTUALMACHINE_H
#define KAI_VIRTUALMACHINE_H

#include <array>
#include <vector>

const int poolSz = 1024;

class VirtualMachine
{
public:
    VirtualMachine();
    ~VirtualMachine();
    void tick();
    int loadProgram(std::vector<int> program, int offset = 0);
    void setProgramCounter(int programCounter);
    void turnOff();
    void run();

private:
    std::array<int, poolSz> memory;
    std::array<int, 5> registers;
    std::array<int, poolSz> stack;
    std::array<int, poolSz> program;
    int &programCounter = registers[3];
    int &stackPointer = registers[4];
    bool isRunning;
};

#endif // KAI_VIRTUALMACHINE_H
