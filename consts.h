//
// Created by Nick on 8/30/2020.
//

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_CONSTS_H
#define PSEUDO_ASSEMBLY_INTERPRETER_CONSTS_H
#include <vector>
#include <QString>
#include <unordered_set>
#include <string>


typedef std::vector<int> longArith;


const QString MARKER_LINE = "MARKER";
const std::string NO_CONDITION = "NO CONDITION";

const int NO_REGISTER = -1;

std::unordered_set<std::string> available_instructions = {"add", "mov", "sub"};

enum Flags {
   V = 28, C = 29, Z = 30, N = 31
};


#endif //PSEUDO_ASSEMBLY_INTERPRETER_CONSTS_H
