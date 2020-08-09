#include <iostream>
#include <string>
#include "Register.h"
#include "Processor.h"

using namespace std;

int main() {

    string line;
    getline(cin, line);
    Processor processor = Processor();
    processor.execute_command(line);

    return 0;
}