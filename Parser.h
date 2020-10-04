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
    static longArith string_to_longArith(const string& num);

public:
    explicit Parser(int arrays_size) {
        this->arrays_size = arrays_size;
    }

    const int NO_REGISTER = -1;
    static vector <string> split_operands(string line);
    bin from_dec_to_binary(const string& operand);
    static string from_bin_to_string(const bin& binary);
    vector <int> get_registers_indices(vector <string> operands);
    static bool contains_splitters(char character);
    static void divide_dec_by_two(const longArith& num, longArith& result, int& remainder);
};


#endif //PSEUDO_ASSEMBLY_INTERPRETER_PARSER_H
