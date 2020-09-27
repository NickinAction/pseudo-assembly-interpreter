//
// Created by Nick on 8/30/2020.
//

#include "Parser.h"
#include <iostream>

using namespace std;

//constexpr const array<char, 4> Parser::splitters = {' ', ',', '\t', '\r'};

bool Parser::contains_splitters(char character) {
    for (int i = 0; i < splitters.size(); ++i) {
        if(character == splitters[i]) return true;
    }

    return false;
}

vector <string> Parser::split_operands(string line) {
    vector <string> operands;

    int prev_splitter = -1;
    string cutout;

    for (int i = 0; i < line.size(); ++i) {
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

bin Parser::from_dec_to_binary(const string& operand) {
    bin return_arr;
    return_arr.resize(arrays_size);

    cout << "operand: " << operand << endl;

    int int_op = stoi(operand), remainder;
    // TODO: do this without stoi

    for (int i = 0; i < arrays_size; i++) {
        remainder = int_op%2;
        int_op/=2;
        return_arr[i] = remainder;
    }

    cout << "got to the end";
    return return_arr;
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

    if(operands.size() == 2) {
        return_registers_indices.insert(return_registers_indices.begin(), return_registers_indices[0]);
    } //! get_registers()?
    return return_registers_indices;
}

string Parser::from_bin_to_string(const bin &binary) {
    int digits = binary.size();
    //cout << "Digits: " << digits << endl;
    char charArray[digits+1];

    charArray[digits] = '\0';

    for (int i = 0; i < digits; i++) charArray[i] = '.';

    for (int i = 0; i < digits; ++i) {
        charArray[i] = (binary[i] == 1) ? '1' : '0';
        cout << i << " " << charArray << " binary[i] " << binary[i] << endl;
    }

    return string(charArray);
}
