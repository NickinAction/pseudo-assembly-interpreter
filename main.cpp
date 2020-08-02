#include <iostream>
#include <string>

using namespace std;

bool r1[32];
bool r2[32];
bool r3[32];
bool r4[32];
bool r5[32];
bool r6[32];
bool r7[32];
bool r8[32];

void parse_command (string line) {
    size_t first_op_pos, second_op_pos, third_op_pos;
    string first_loc, second_loc, destination;
    string instruction;
    size_t space_loc = line.find(' ');

    if (space_loc == std::string::npos) {
        throw std::runtime_error("Space in the command is not found");
    }
    instruction = line.substr(0, space_loc);
    cout << "instruction: " << instruction << endl;

    line = line.substr(space_loc); // line is now only operands

    first_op_pos = line.find('r');
    first_loc = line.substr(first_op_pos + 1, 1);

    second_op_pos = line.find('r', first_op_pos);
    second_loc = line.substr(second_op_pos + 1, 1);

    third_op_pos = line.find('r', second_op_pos);

    if(third_op_pos != string::npos){ // if third argument exists
        destination = first_loc;
        first_loc = second_loc;
        second_loc = line.substr(third_op_pos + 1, 1);

        destination = 'r' + destination;
    }
    else { // if third argument doesnt exist
        destination = 'r' + first_loc;
    }

    first_loc = 'r' + first_loc;
    second_loc = 'r' + second_loc;

    if (instruction == "add") {
        cout << "adding " << first_loc << " and " << second_loc << " and putting into " << destination << endl;
    }
}

int main() {

    string line;
    getline(cin, line);
    parse_command(line);

    return 0;
}