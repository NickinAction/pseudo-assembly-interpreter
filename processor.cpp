#include <iostream>
#include <string>
#include "Processor.h"
#include <vector>
#include "ALU.h"
#include "Register.h"

using namespace std;

vector <Register*> Processor::get_registers(vector<string> operands) {

    vector <Register*> return_registers;
    vector<int> register_indices = parser->get_registers_indices(operands);
    cout << "Register indices:";
    for (int i: register_indices) {
        cout << " " << i;
    }
    cout << endl;

    for (unsigned i = 0; i < register_indices.size(); ++i) {
        int ri = register_indices[i];
        if(ri >= 0 && ri < registers.size()) {
            cout << "Register added: " << ri << endl;
            return_registers.emplace_back(&registers[ri]);
        }
        else if (ri == parser->NO_REGISTER) {
            cout << "No standard register provided" << endl;
            cout << "\":" << operands[i]  << "\":" << endl;
            vector<bool> bin_value = parser->from_dec_to_binary(operands[i].substr(1));
            cout << "value to write in extra register: ";
            for (int i: bin_value) {
                cout << i;
            }
            cout << endl;
            int num = extra_registers_used;
            extra_registers[num].copy(bin_value); // converting straight to Register
            return_registers.emplace_back(&extra_registers[num]);
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

Register* Processor::get_extra_register() {
    extra_registers_used++;
    return &extra_registers[extra_registers_used];
}

void Processor::execute_command(string &instruction, Register* destination, Register* first_op, Register* second_op) {
    if (instruction == "add") {
        ALU::add(destination, first_op, second_op);
    }
    else if (instruction == "sub") {
        ALU::sub(destination, first_op, second_op, get_extra_register());
    }
    else if (instruction == "mov") {
        ALU::mov(destination, second_op);
    }
    else {
        throw runtime_error("Unrecognised command");
    }
}

void Processor::print_state() {
    for (unsigned i = 0; i < registers.size(); ++i) {
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
