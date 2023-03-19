#include <cstdio>
#include "VirtualMachine.h"
#include "Instructions.h"

int main(int argc, char **argv)
{
    std::printf("Hello, World!\n");
    VirtualMachine vm;
    vm.loadProgram({
        MOV, 1, 10,
        MOV, 2, 30,
        ADD,
        PRINT, 0,
        MOV, 0, '\n', PRINT, 1,
        MOV, 0, 'H', PRINT, 1,
        MOV, 0, 'E', PRINT, 1,
        MOV, 0, 'L', PRINT, 1,
        MOV, 0, 'L', PRINT, 1,
        MOV, 0, 'O', PRINT, 1,
        MOV, 0, ' ', PRINT, 1,
        MOV, 0, 'W', PRINT, 1,
        MOV, 0, 'O', PRINT, 1,
        MOV, 0, 'R', PRINT, 1,
        MOV, 0, 'L', PRINT, 1,
        MOV, 0, 'D', PRINT, 1,
        MOV, 0, '!', PRINT, 1,
        MOV, 0, '\n', PRINT, 1,
        HALT
    });
    vm.run();
    vm.loadProgram(
        {
            MOV, 0, 10,
            MOV, 1, 20,
            ADD,
            PRINT, 0,
            MOV, 0, '\n', PRINT, 1,
            HALT
        }
    );
    vm.run();
    return 0;
}
