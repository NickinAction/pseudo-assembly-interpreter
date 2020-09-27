//
// Created by Nick on 9/27/2020.
//

#include "gtest/gtest.h"
#include "ALU.h"
#include "consts.h"
#include "Processor.h"

class ALU_tester {
public:

    ALU_tester();

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

ALU_tester::ALU_tester() {
    destination = new Register();
    first_reg = new Register();
    second_reg = new Register();
    test_destination = new Register();

    ALU_tester::fill("10", destination);
    ALU_tester::fill("4", first_reg);
    ALU_tester::fill("6", second_reg);
}

TEST (ALU_tester, add) {
    ALU_tester tester = ALU_tester();

    ALU::add(tester.test_destination,tester.first_reg, tester.second_reg);

    EXPECT_TRUE(ALU_tester::compare(*tester.destination, *tester.test_destination));
}