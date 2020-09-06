#include <iostream>
#include <string>
#include "Processor.h"
#include <vector>

using namespace std;



void Processor::mov(Register *destination, Register *location) {

}

void Processor::add(Register *destination, Register *first_reg, Register *second_reg) {

    int carry = 0, sum, value;
    for (int i = 0; i < Register::size; i++) {
        sum = first_reg->value[i] + second_reg->value[i] + carry;
        value = sum%2;
        carry = sum/2;

        destination->value[i] = value;
    }
    bool overflow = (carry == 1);
}

void Processor::sub(Register *destination, Register *first_reg, Register *second_reg) {

    int num = extra_registers_used;
    extra_registers_used++;
    twos_complement(&extra_registers[num], second_reg);
    add(destination, first_reg, &extra_registers[num]);
}

void Processor::twos_complement(Register *destination, Register *original) {
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

vector <Register*> Processor::get_registers(vector<string> operands) {

    vector <Register*> return_registers;
    vector<int> register_indices = parser->get_registers_indices(operands);

    for (int i = 0; i < register_indices.size(); ++i) {
        int ri = register_indices[i];
        if(ri >= 0 && ri < registers.size()) {
            return_registers.emplace_back(&registers[ri]);
        }
        else if (ri == parser->NO_REGISTER) {
            vector<bool> bin_value = parser->from_dec_to_binary(operands[i].substr(1));
            extra_registers[extra_registers_used].copy(bin_value); // converting straight to Register
            return_registers.emplace_back(&extra_registers[extra_registers_used]);
            cout << "Extra registers used: " << extra_registers_used << endl;
            extra_registers_used++;
        }
        else {
            throw runtime_error("get_registers(): register index out of range");
        }
    }

    return return_registers;
}

void Processor::process_command(string line) {
    auto operands = parser->split_operands(line);
    string instruction = operands[0];
    operands.erase(operands.begin()); // remove the instruction
    extra_registers_used = 0;

    auto cur_registers = get_registers(operands);

    execute_command(instruction, cur_registers[0], cur_registers[1], cur_registers[2]);

    print_state();

}

void Processor::execute_command(string &instruction, Register* destination, Register* first_op, Register* second_op) {
    if (instruction == "add") {
        add(destination, first_op, second_op);
    }
    else if (instruction == "sub") {
        sub(destination, first_op, second_op);
    }
    /*
    else if (instruction == "mov") {

    }
     */
    else {
        throw runtime_error("Unrecognised command");
    }
}


void Processor::print_state() {
    for (int i = 0; i < registers.size(); ++i) {
        cout << "R" << i << ": ";
        for (int j = Register::size-1; j >= 0; j--) {
            cout << registers[i].value[j];
        }
        cout << endl;
    }

    for (int k = 0; k < 3; ++k) {
        cout << "EXTRA " << k << ": ";
        for (int j = Register::size-1; j >= 0; j--) {
            cout << extra_registers[k].value[j];
        }
        cout << endl;
    }
}