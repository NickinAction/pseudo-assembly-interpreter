//
// Created by Nick on 8/9/2020.
//
#include <array>
#include "Register.h"
#include "Parser.h"
#include <vector>

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
#define PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H

using namespace std;

class Processor {

public:
    Processor() {
        parser = new Parser(REGISTER_SIZE);
    }
    void process_command(string line);
    void execute_command(string& instruction, Register* destination, Register* first_op, Register* second_op);
private:
    const int REGISTER_SIZE = Register::size;
    Parser* parser;
    array <Register, 16> registers;
    Register extra_registers[3];
    int extra_registers_used = 0;
    Register CPSR;
    void print_state();
    vector <Register*> get_registers(vector <string> operands);
    static void twos_complement(Register* destination, Register* original);
    static void mov(Register* destination, Register* source);
    static void add(Register* destination, Register* first_reg, Register* second_reg);
    void sub(Register* destination, Register* first_reg, Register* second_reg);
};
#endif //PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
