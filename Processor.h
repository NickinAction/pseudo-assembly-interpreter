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
    void execute_command(string instruction);
private:
    Register registers[13];
    Register extra_registers[3];
    Register CPSR;
    vector <string> split_operands(string line);
    vector <Register> get_registers(vector <string> operands);
    void mov(string destination, string location);
    void add(string destination, string first_op, string second_op);
    bool contains_splitters(char character);
    const array<char, 4> splitters = {' ', ',', '\t', '\r'};
};
#endif //PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
