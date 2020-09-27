//
// Created by Nick on 9/27/2020.
//

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_ALU_H
#define PSEUDO_ASSEMBLY_INTERPRETER_ALU_H


#include "Register.h"

class ALU {

public:

    static void twos_complement(Register* destination, Register* original);
    static void mov(Register* destination, Register* source);
    static void add(Register* destination, Register* first_reg, Register* second_reg);
    static void sub(Register* destination, Register* first_reg, Register* second_reg, Register* extra);
};


#endif //PSEUDO_ASSEMBLY_INTERPRETER_ALU_H
