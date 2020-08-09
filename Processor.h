//
// Created by Nick on 8/9/2020.
//
#include <string>
#include "Register.h"

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
#define PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H

class Processor {
    Register registers[10];
public:
    void parse_line(std::string line);
private:
    void mov(std::string destination, std::string location);
    void add(std::string destination, std::string first_op, std::string second_op);
};
#endif //PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
