//
// Created by Nick on 8/30/2020.
//
#include <array>
#include "Register.h"
#include <vector>
#include "consts.h"

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_PARSER_H
#define PSEUDO_ASSEMBLY_INTERPRETER_PARSER_H

using namespace std;
class Parser {
private:
    int arrays_size;
    inline constexpr const static array<char, 4> splitters = {' ', ',', '\t', '\r'};

public:
    explicit Parser(int arrays_size) {
        this->arrays_size = arrays_size;
    }

    const int NO_REGISTER = -1;
    static vector <string> split_operands(string line);
    bin from_dec_to_binary(const string& operand);
    vector <int> get_registers_indices(vector <string> operands);
    static bool contains_splitters(char character);
};


#endif //PSEUDO_ASSEMBLY_INTERPRETER_PARSER_H
