#include <iostream>
#include <string>
#include "Processor.h"

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

void Processor::parse_line(string line) {
    size_t first_op_pos, second_op_pos, third_op_pos;
    string first_loc, second_loc, destination;
    string instruction;
    size_t space_loc = line.find(' ');

    if (space_loc == std::string::npos) {
        throw std::runtime_error("No ' ' character in line");
    } // throw error if no spaces found in current line


    instruction = line.substr(0, space_loc); // determine the instruction of the line
    cout << "instruction: " << instruction << endl; // output

    line = line.substr(space_loc); // line is now only operands, removes the instruction

    first_op_pos = line.find('r'); // finds the first occurance of 'r' in the line
    first_loc = line.substr(first_op_pos + 1, 1); // removes the previously found 'r' character from the

    second_op_pos = line.find('r', first_op_pos + 1);
    second_loc = line.substr(second_op_pos + 1, 1);

    third_op_pos = line.find('r', second_op_pos + 1); // no need for removing the last 'r'

    if (third_op_pos != string::npos) { // if third argument exists (only sub or add)
        destination = first_loc; // moves all values along by one
        first_loc = second_loc;
        second_loc = line.substr(third_op_pos + 1, 1);

        destination = 'r' + destination;
    } else { // if third argument doesnt exist
        destination = 'r' + first_loc;
    }

    //first_loc = 'r' + first_loc;
    //second_loc = 'r' + second_loc;

    if (instruction == "add") {
        cout << "adding r" << first_loc << " and r" << second_loc << " and putting into " << destination << endl;
        add(destination, first_loc, second_loc);
    }
    if (instruction == "sub") {
        cout << "subtracting " << first_loc << " from " << second_loc << " and putting into " << destination << endl;
    }

}