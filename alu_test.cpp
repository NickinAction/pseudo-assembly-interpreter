//
// Created by Nick on 9/27/2020.
//

#include "gtest/gtest.h"
#include "ALU.h"
#include "consts.h"
#include "Processor.h"

class ALU_tester {
public:

    ALU_tester(const string& destination, const string& first_reg, const string& second_reg);

    static void fill(const string& operand, Register* reg) {
        Parser parser(Register::size);
        bin new_operands = parser.from_dec_to_binary(operand);

    }

    static bool compare(Register a, Register b) {
        for (int i = 0; i < Register::size; i++) {
            if (a.value[i] != b.value[i]) return false;
        }
        return true;
    }

    Register *destination;
    Register *first_reg, *second_reg, *test_destination;
};

ALU_tester::ALU_tester(const string& destination, const string& first_reg, const string& second_reg) {
    this->destination = new Register();
    this->first_reg = new Register();
    this->second_reg = new Register();
    test_destination = new Register();

    ALU_tester::fill(destination, this->destination);
    ALU_tester::fill(first_reg, this->first_reg);
    ALU_tester::fill(second_reg, this->second_reg);
}

TEST (ALU_tester, add) {
    ALU_tester tester = ALU_tester("10", "6", "4");

    ALU::add(tester.test_destination,tester.first_reg, tester.second_reg);

    EXPECT_TRUE(ALU_tester::compare(*tester.destination, *tester.test_destination));
}


// TODO: fix the test
TEST (ALU_tester, addOverflow) {
    ALU_tester tester = ALU_tester("0", "2147483647", "2147484647");

    ALU::add(tester.test_destination,tester.first_reg, tester.second_reg);

    EXPECT_TRUE(ALU_tester::compare(*tester.destination, *tester.test_destination));
}