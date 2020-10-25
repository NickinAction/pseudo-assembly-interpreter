//
// Created by Nick on 8/9/2020.
//

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H
#define PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H

//#include "consts.h"
#include "Parser.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Register {
public:
    static const int size = 32;
    Register() {
        for (bool & i : this->value) {
            i = false;
        }
    }
    bool value[size]{};
    void copy(Register to_copy) {
        for (int i = 0; i < size; ++i) {
            value[i] = to_copy.value[i];
        }
    }
    void copy(binary to_copy) {
        for (int i = 0; i < to_copy.size(); ++i) {
            value[i] = to_copy[i];
        }
    }
    void increment() {
        int carry = 1, sum, new_value;
        for (bool & i : this->value) {
            if(carry == 0) break;
            sum = i + carry;
            new_value = sum%2;
            carry = sum/2;

            i = new_value;
        }
    }
    string toString() {
        char arr [this->size];

        for (int i = 0; i < this->size; i++) {
            arr[i] = this->value[i] + '0';
        }
        string s = string(arr, this->size);
        reverse(s.begin(), s.end());
        return s;
    }
};


#endif //PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H
