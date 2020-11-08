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
#include "registermemory.h"

using namespace std;

class Processor {
private:
    ALU* alu;

public:
    Processor() {;
        alu = new ALU();
    }

    void process_command(vector <string> operands);
    void execute_command(string& instruction, Register* destination, Register* first_op, Register* second_op);

//private:

    vector <Register*> get_registers(vector <string> operands);
    Register* get_extra_register();
    int extra_registers_used = 0;
};
#endif //PSEUDO_ASSEMBLY_INTERPRETER_PROCESSOR_H
