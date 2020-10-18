#include <iostream>
#include <string>
#include "Register.h"
#include "Processor.h"

using namespace std;

int main() {

    string line;
    bool eof_reached;
    do {
        getline(cin, line);
        Processor processor = Processor();
        processor.process_command(line);
        eof_reached = cin.eof();

    } while(!eof_reached);

    return 0;
}