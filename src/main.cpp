#include "Instructions.h"
#include "VirtualMachine.h"
#include <cstdio>

int main(int argc, char **argv)
{
    VirtualMachine vm;

    vm.setProgramCounter(0);

    vm.turnOff();
    int offset = 0;

    std::vector<int> printString = {
        POP,
        PRINT,
        1,
        MOVR,
        1,
        4,
        MOV,
        2,
        1,
        SUB,
        MOV,
        1,
        offset + 0,
        JNE,
        POP,
        JMP,
    };

    offset = vm.loadProgram(printString, 0);

    std::printf("Offset: %d\n", offset);

    std::vector<int> printHelloWorld = {
        MOV,
        0,
        offset + 60,
        PUSH,
        MOV,
        0,
        '\n',
        PUSH,
        MOV,
        0,
        '!',
        PUSH,
        MOV,
        0,
        'D',
        PUSH,
        MOV,
        0,
        'L',
        PUSH,
        MOV,
        0,
        'R',
        PUSH,
        MOV,
        0,
        'O',
        PUSH,
        MOV,
        0,
        'W',
        PUSH,
        MOV,
        0,
        ' ',
        PUSH,
        MOV,
        0,
        'O',
        PUSH,
        MOV,
        0,
        'L',
        PUSH,
        MOV,
        0,
        'L',
        PUSH,
        MOV,
        0,
        'E',
        PUSH,
        MOV,
        0,
        'H',
        PUSH,
        MOV,
        0,
        0,
        JMP,
        HALT,
    };

    std::printf("size: %lu, %d %d\n", printHelloWorld.size(), printHelloWorld[60],
                HALT);

    vm.setProgramCounter(offset);

    offset = vm.loadProgram(printHelloWorld, offset);

    vm.run();

    return 0;
}
