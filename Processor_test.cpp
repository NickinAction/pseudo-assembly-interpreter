//
// Created by Nick on 9/26/2020.
//

#include "gtest/gtest.h"
#include "Processor.h"
#include "consts.h"

TEST(Processor, get_registers_one_number) {

    Processor processor;

    vector <string> operands = {"r0", "r1", "#1"};

    auto cur_registers = processor.get_registers(operands);

    EXPECT_EQ(cur_registers[0], &processor.registers[0]);
    EXPECT_EQ(cur_registers[1], &processor.registers[1]);
    EXPECT_EQ(cur_registers[2], &processor.extra_registers[0]);

}

TEST(Processor, get_registers_two_numbers) {

    Processor processor;

    vector <string> operands = {"r0", "#2", "#1"};

    auto cur_registers = processor.get_registers(operands);

    EXPECT_EQ(cur_registers[0], &processor.registers[0]);
    EXPECT_EQ(cur_registers[1], &processor.extra_registers[0]);
    EXPECT_EQ(cur_registers[2], &processor.extra_registers[1]);

}

TEST(Processor, get_registers_no_numbers) {

    Processor processor;

    vector <string> operands = {"r0", "r1", "r2"};

    auto cur_registers = processor.get_registers(operands);

    EXPECT_EQ(cur_registers[0], &processor.registers[0]);
    EXPECT_EQ(cur_registers[1], &processor.registers[1]);
    EXPECT_EQ(cur_registers[2], &processor.registers[2]);

}

/*
TEST (Processor, process_command) {
    Processor processor;

    string line = "";
}
 */


