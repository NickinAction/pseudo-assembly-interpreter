//
// Created by Nick on 9/27/2020.
//

#include "ALU.h"
#include <iostream>
#include "Register.h"

using namespace std;

void ALU::mov(Register *destination, Register *location) {
    destination->copy(*location);
}

void ALU::add(Register *destination, Register *first_reg, Register *second_reg) {

    int carry = 0, sum, value;
    for (int i = 0; i < Register::size; i++) {
        sum = first_reg->value[i] + second_reg->value[i] + carry;
        value = sum%2;
        carry = sum/2;

        destination->value[i] = value;
    }
    bool overflow = (carry == 1);
}

void ALU::sub(Register *destination, Register *first_reg, Register *second_reg, Register* extra) {
    twos_complement(extra, second_reg);
    add(destination, first_reg, extra);
}

void ALU::twos_complement(Register *destination, Register *original) {
    for (int i = 0; i < Register::size; ++i) {
        destination->value[i] = !original->value[i];
    }

    destination->increment();

    cout << "Two's complement: ";
    for (bool i : destination->value) {
        cout << i;
    }
    cout << endl;
}
