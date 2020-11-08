//
// Created by Nick on 8/9/2020.
//

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
#define PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H

#include <array>
#include "Register.h"
#include <vector>
#include "ALU.h"
#include <map>
#include <QVector>
#include <QString>
#include <QMap>

using namespace std;

class Processor {
private:
    Parser* parser;
    ALU* alu;

public:
    Processor() {
        parser = new Parser(REGISTER_SIZE);
        alu = new ALU();
    }

    QMap <QString, int> branches;
    void process_command(string line, int &iterator);
    void execute_command(string& instruction, Register* destination, Register* first_op, Register* second_op);
    bool execute_branch(string& condition);

//private:

    const int REGISTER_SIZE = Register::size;
    array <Register, 16> registers;
    Register extra_registers[3];
    Register CPSR;
    void print_state();
    vector <Register*> get_registers(vector <string> operands);
    Register* get_extra_register();
    int extra_registers_used = 0;
    void collect_markers(QVector <QString> &codeLines);
};
#endif //PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
