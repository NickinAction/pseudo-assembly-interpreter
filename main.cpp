#include <iostream>
#include <string>
#include "Register.h"

using namespace std;

int main() {

    string line;
    getline(cin, line);
    processor->parse_line(line);

    return 0;
}