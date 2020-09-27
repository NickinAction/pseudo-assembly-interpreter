//
// Created by Nick on 9/27/2020.
//

#include "gtest/gtest.h"
#include "ALU.h"
#include "consts.h"
#include "Processor.h"

class ALU_tester : public ::testing::Environment {
public:

    void SetUpTestCase();

    static void fill(string operand, Register* reg) {
        Parser parser(reg->size);
        bin new_operands = parser.from_dec_to_binary(operand);

    }

    static bool compare(Register a, Register b) {
        if (a.size != b.size) return false;
        for (int i = 0; i < a.size; i++) {
            if (a.value[i] != b.value[i]) return false;
        }
        return true;
    }

    static Register *destination;
    static Register *first_reg, *second_reg, *test_destination;
};

void ALU_tester::SetUpTestCase() {
    destination = new Register();
    first_reg = new Register();
    second_reg = new Register();
    test_destination = new Register();

    ALU_tester::fill("10", destination);
    ALU_tester::fill("4", first_reg);
    ALU_tester::fill("6", second_reg);
}

TEST (ALU_tester, add) {

    ALU::add(ALU_tester::test_destination, ALU_tester::first_reg, ALU_tester::second_reg);

    EXPECT_TRUE(ALU_tester::compare(*ALU_tester::destination, *ALU_tester::test_destination));
}