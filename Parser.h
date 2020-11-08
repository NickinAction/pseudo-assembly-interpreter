//
// Created by Nick on 8/30/2020.
//

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_PARSER_H
#define PSEUDO_ASSEMBLY_INTERPRETER_PARSER_H

#include <array>
#include <vector>
#include "consts.h"
#include <QVector>
#include <QString>


typedef std::vector<bool> binary;

using namespace std;

class Parser {
private:
    unsigned arrays_size;
    inline constexpr const static array<char, 4> splitters = {' ', ',', '\t', '\r'};
    static longArith string_to_longArith(const string& num);

public:
    explicit Parser(unsigned arrays_size) {
        this->arrays_size = arrays_size;
    }

    static string branch_condition(string str);
    static vector <string> split_operands(string line);
    binary from_dec_to_binary(const string& operand);
    static string from_bin_to_string(const binary& binary);
    vector <int> get_registers_indices(vector <string> operands);
    static bool contains_splitters(char character);
    static void divide_dec_by_two(const longArith& num, longArith& result, int& remainder);
    static void remove_surrounding_spaces(QVector <QString> codeLines);
};

#endif //PSEUDO_ASSEMBLY_INTERPRETER_PARSER_H
