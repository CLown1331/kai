//
// Created by Araf Al Jami on 19/03/2023.
//

#ifndef KAI_INSTRUCTIONS_H
#define KAI_INSTRUCTIONS_H

enum
{
    // Arithmetic
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    // Bitwise
    AND,
    OR,
    XOR,
    NOT,
    SHL,
    SHR,
    // Control
    JMP,
    JEQ,
    JNE,
    JLT,
    JGT,
    JLE,
    JGE,
    // Stack
    PUSH,
    POP,
    // Memory
    LOAD,
    STORE,
    MOV,
    MOVR,
    // I/O
    PRINT,
    READ,
    // Misc
    NOP,
    HALT
};

#endif // KAI_INSTRUCTIONS_H
