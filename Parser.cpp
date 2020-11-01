//
// Created by Nick on 8/30/2020.
//

#include "Parser.h"
#include <iostream>

using namespace std;

//constexpr const array<char, 4> Parser::splitters = {' ', ',', '\t', '\r'};

bool Parser::contains_splitters(char character) {
    for (unsigned i = 0; i < splitters.size(); ++i) {
        if(character == splitters[i]) return true;
    }

    return false;
}

vector <string> Parser::split_operands(string line) {
    vector <string> operands;

    int prev_splitter = -1;
    string cutout;

    for (unsigned i = 0; i < line.size(); ++i) {
        if(contains_splitters(line[i])) {
            cutout = line.substr(prev_splitter+1, i-prev_splitter-1);
            prev_splitter = i;
            if (cutout.empty()) continue;
            else operands.emplace_back(cutout);
        }
    }
    // Take the last operand that goes after the splitter, if present
    cutout = line.substr(prev_splitter+1);
    if (!cutout.empty()) {
        operands.emplace_back(cutout);
    }
    // "add r1, #2, #2 "
    cout << "operands right after split: ";
    for (const string& op: operands) {
        cout << "\"" << op << "\" ";
    }
    cout << endl;

    return operands;
}

binary Parser::from_dec_to_binary(const string& operand) {
    auto operand_la = string_to_longArith(operand);
    binary return_arr;
    return_arr.resize(arrays_size);

    cout << "operand: " << operand << endl;

    int remainder;

    longArith temp;

    for (unsigned i = 0; i < arrays_size; i++) {
        remainder = operand_la[i]%2;
        divide_dec_by_two(operand_la, temp, remainder);
        operand_la = temp;
        return_arr[i] = remainder;
    }

    cout << "got to the end";
    return return_arr;
}

longArith Parser::string_to_longArith(const string& num) {
    longArith converted;

    for (char c : num) {
        converted.emplace_back(c - '0');
    }
    return converted;
}

void Parser::divide_dec_by_two(const longArith& num, longArith& result, int& remainder) {

    int curSubtrahend = 0;
    int curResult = 0;
    result.clear();

    bool first_number = true;

    for (int digit : num) {
        curSubtrahend = (curSubtrahend*10) + digit;
        curResult = curSubtrahend /2;
        if (curResult > 0) {
            result.emplace_back(curResult);
            if(first_number) first_number = false;
            curSubtrahend = curSubtrahend%2;
        }
        else {
            if(!first_number) result.emplace_back(0);
        }
    }

    if(first_number) result.emplace_back(0);

    remainder = curSubtrahend;
}

vector<int> Parser::get_registers_indices(vector<string> operands) {
    cout << "Number of operands: " << operands.size() << endl;
    vector<int> return_registers_indices;

    for (auto & operand : operands) {

        cout << "Current operand: \"" << operand << "\"" << endl;

        char operand_prefix = operand[0];
        // checking for first symbol (r, #, b, x)

        switch(operand_prefix) {
            case 'r':
                return_registers_indices.emplace_back(stoi(operand.substr(1)));
                break;
            case '#':
                return_registers_indices.emplace_back(this->NO_REGISTER);
                break;
            default:
                string error_message = "Cannot decipher the constant value: operand starts with ";
                error_message.push_back(operand_prefix);
                throw runtime_error(error_message);

        }
        //TODO: hexadecimal + binary
        /*else if(operands[i][0] == 'b') {
        }
        else if(operands[i][0] == 'x') {

        }*/
    }

    return return_registers_indices;

}

string Parser::from_bin_to_string(const binary &binary) {
    unsigned digits = binary.size();
    //cout << "Digits: " << digits << endl;
    char charArray[digits+1];

    charArray[digits] = '\0';

    for (unsigned i = 0; i < digits; i++) charArray[i] = '.';

    for (unsigned i = 0; i < digits; ++i) {
        charArray[i] = (binary[i] == 1) ? '1' : '0';
        cout << i << " " << charArray << " binary[i] " << binary[i] << endl;
    }

    return string(charArray);
}
