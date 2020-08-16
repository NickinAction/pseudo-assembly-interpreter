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

bool Processor::contains_splitters(char character) {
    for (int i = 0; i < splitters.size(); ++i) {
        if(character == splitters[i]) return true;
    }

    return false;
}

vector <string> Processor::split_operands(string line) {
    vector <string> operands;

    int prev_splitter = -1;
    string cutout = "";

    for (int i = 0; i < line.size(); ++i) {
        if(contains_splitters(line[i])) {
            cutout = line.substr(prev_splitter+1, i-prev_splitter-1);
            prev_splitter = i;
            if (cutout == "") continue;
            else operands.emplace_back(cutout);
        }
    }
    return operands;

}

Register Processor::from_dec_to_binary(string operand) {
    Register return_register;

    int int_op = stoi(operand), remainder;
    for (int i = 0; i < Register::size; i++) {
        remainder = int_op%2;
        int_op/=2;
        return_register.value[i] = remainder;
    }

    return return_register;


}

vector <Register*> Processor::get_registers(vector<string> operands) {

    vector <Register*> return_registers;

    int extra_registers_used = 0; //tracks how many extra registers were used.
    for (auto & operand : operands) {

        if(operand[0] == 'r') {
            cout << "Operand: " << operand << endl;
            return_registers.emplace_back(&registers[stoi(operand.substr(1))]);//// checking for first symbol (r, #, b, x)
            cout << "emplaced successfully" << endl;
        }
        else if(operand[0] == '#') {
            extra_registers[extra_registers_used].copy(from_dec_to_binary(operand.substr(1))); // converting straight to Register
            return_registers.emplace_back(&extra_registers[extra_registers_used]);
            extra_registers_used++;
        }
        else {
            throw runtime_error("Cannot decipher the constant value");
        }
        //TODO: hexadecimal + binary
        /*else if(operands[i][0] == 'b') {
        }
        else if(operands[i][0] == 'x') {

        }*/
    }

    if(operands.size() == 2) {
        return_registers.insert(return_registers.begin(), return_registers.front());
    }

    return return_registers;
}

void Processor::process_command(string line) {
    auto operands = split_operands(line);
    string instruction = operands[0];
    operands.erase(operands.begin());

    auto cur_registers = get_registers(operands);



    execute_command(instruction, cur_registers[0], cur_registers[1], cur_registers[2]);

}

void Processor::execute_command(string &instruction, Register* destination, Register* first_op, Register* second_op) {
    if (instruction == "add") {
        add(destination, first_op, second_op);
    }
    /*
    else if (instruction == "sub") {

    }
    else if (instruction == "mov") {

    }
     */
    else {
        throw runtime_error("Unrecognised command");
    }
}
