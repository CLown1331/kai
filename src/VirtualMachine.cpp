//
// Created by Araf Al Jami on 19/03/2023.
//

#include "VirtualMachine.h"
#include "Instructions.h"
#include <cstdio>

VirtualMachine::VirtualMachine()
{
    registers[0] = 0;
    registers[1] = 0;
    registers[2] = 0;
    registers[3] = 0;
    registers[4] = 0;
}

VirtualMachine::~VirtualMachine() {}

void VirtualMachine::tick()
{
    int instruction = program[programCounter++];
    int firstOperand;
    int secondOperand;
    switch (instruction)
    {
    case ADD:
        registers[0] = registers[1] + registers[2];
        break;
    case SUB:
        registers[0] = registers[1] - registers[2];
        break;
    case MUL:
        registers[0] = registers[1] * registers[2];
        break;
    case DIV:
        registers[0] = registers[1] / registers[2];
        break;
    case MOD:
        registers[0] = registers[1] % registers[2];
        break;
    case AND:
        registers[0] = registers[1] & registers[2];
        break;
    case OR:
        registers[0] = registers[1] | registers[2];
        break;
    case XOR:
        registers[0] = registers[1] ^ registers[2];
        break;
    case NOT:
        registers[0] = ~registers[1];
        break;
    case SHL:
        registers[0] = registers[1] << registers[2];
        break;
    case SHR:
        registers[0] = registers[1] >> registers[2];
        break;
    case CMP:
        registers[0] = registers[1] - registers[2];
        break;
    case JMP:
        programCounter = registers[0];
        break;
    case JEQ:
        if (registers[0] == 0)
        {
            programCounter = registers[1];
        }
        break;
    case JNE:
        if (registers[0] != 0)
        {
            programCounter = registers[1];
        }
        break;
    case JLT:
        if (registers[0] < 0)
        {
            programCounter = registers[1];
        }
        break;
    case JGT:
        if (registers[0] > 0)
        {
            programCounter = registers[1];
        }
        break;
    case JLE:
        if (registers[0] <= 0)
        {
            programCounter = registers[1];
        }
        break;
    case JGE:
        if (registers[0] >= 0)
        {
            programCounter = registers[1];
        }
        break;
    case PUSH:
        stack[stackPointer] = registers[0];
        stackPointer++;
        break;
    case POP:
        stackPointer--;
        registers[0] = stack[stackPointer];
        break;
    case LOAD:
        registers[0] = memory[registers[1]];
        break;
    case STORE:
        memory[registers[1]] = registers[0];
        break;
    case MOV:
        firstOperand = program[programCounter++];
        secondOperand = program[programCounter++];
        registers[firstOperand] = secondOperand;
        break;
    case MOVR:
        firstOperand = program[programCounter++];
        secondOperand = program[programCounter++];
        registers[firstOperand] = registers[secondOperand];
        break;
    case PRINT:
        firstOperand = program[programCounter++];
        if (firstOperand == 0)
        {
            std::printf("%d", registers[0]);
        }
        else
        {
            std::printf("%c", registers[0]);
        }
        break;
    case READ:
        std::scanf("%d", &registers[0]);
        break;
    case NOP:
        break;
    case HALT:
        this->isRunning = false;
        break;
    default:
        std::printf("Unknown instruction: %d\n", instruction);
        break;
    }
}

void VirtualMachine::loadProgram(std::array<int, 1024> program)
{
    this->program = program;
}

int VirtualMachine::loadProgram(std::vector<int> program, int offset)
{
    int size = offset;
    for (int i = 0; i < program.size(); i++)
    {
        this->program[i + offset] = program[i];
        size++;
    }
    return size;
}

void VirtualMachine::setProgramCounter(int programCounter)
{
    this->programCounter = programCounter;
}

void VirtualMachine::turnOff()
{
    this->isRunning = false;
}

void VirtualMachine::run()
{
    this->isRunning = true;
    while (this->isRunning)
    {
        this->tick();
    }
}