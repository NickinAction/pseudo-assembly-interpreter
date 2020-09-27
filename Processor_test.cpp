//
// Created by Nick on 9/26/2020.
//

#include "gtest/gtest.h"
#include "Processor.h"
#include "consts.h"

TEST(Processor, get_registers) {

    Processor processor;

    vector <string> operands = {"r0", "r1", "#1"};

    auto cur_registers = processor.get_registers(operands);

    /*function(int &var) {
        var = 5;
    }

    function(int* var) {
        *var = 5;
    }*/

    EXPECT_EQ(cur_registers[0], &processor.registers[0]);
    EXPECT_EQ(cur_registers[1], &processor.registers[1]);
    EXPECT_EQ(cur_registers[2], &processor.extra_registers[0]);

}