//
// Created by Nick on 8/9/2020.
//
#include <string>
#include <array>
#include "Register.h"
#include <vector>

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
#define PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H

using namespace std;

class Processor {

public:
    void process_command(string line);
    static void execute_command(string& instruction, Register* destination, Register* first_op, Register* second_op);
private:
    Register registers[16];
    Register extra_registers[3];
    Register CPSR;
    vector <string> split_operands(string line);
    static Register from_dec_to_binary(string operand);
    vector <Register*> get_registers(vector <string> operands);
    static void mov(Register* destination, Register* source);
    static void add(Register* destination, Register* first_reg, Register* second_reg);
    bool contains_splitters(char character);
    const array<char, 4> splitters = {' ', ',', '\t', '\r'};
};
#endif //PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
