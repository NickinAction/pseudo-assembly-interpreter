#include <iostream>
#include <string>
#include "Processor.h"
#include <vector>

using namespace std;



void Processor::mov(string destination, string location) {
    if (location[0] == 'r') {
        destination = destination.substr(1);
        string value = value.substr(1);
        registers[stoi(destination)].copy(registers[stoi(value)]);
        cout << "moved " << value[1] << " into " << destination << endl;
    } else if (location[0] == '#') {
        destination = destination.substr(1); // destination is now a number, removed 'r'
        string value = location.substr(1);
        registers[stoi(destination)].copy(registers[stoi(value)]);
        cout << "moved #" << value << " into r" << destination << endl;
    } else if (location[0] == 'x') {
        //hex
    }

}

void Processor::add(string destination, string first_op, string second_op) {

    int first = stoi(first_op), second = stoi(second_op);
    mov(destination, "#" + to_string(first + second));
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
            cutout = line.substr(prev_splitter, i-prev_splitter-1);
            prev_splitter = i;
            if (cutout == "") continue;
            else operands.emplace_back(cutout);
        }
    }

}

vector <Register> Processor::get_registers(vector<string> operands) {

}

void Processor::process_command(string line) {
    auto operands = split_operands(line);
    string instruction = operands[0];
    operands.erase(operands.begin());

    auto cur_registers = get_registers(operands);

    // execute_command(instruction, register1, register2, register3);

}

void Processor::execute_command(string instruction) {
    if (instruction == "add") {

    }
    else if (instruction == "sub") {

    }
    else if (instruction == "mov") {

    }
    else {
        throw runtime_error("Unrecognised command");
    }
}