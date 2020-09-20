//
// Created by rony on 20.09.20.
//
#include "gtest/gtest.h"
#include "Parser.h"

TEST(Parser, split1) {
    ASSERT_TRUE(Parser::contains_splitters(' '));
}


TEST(Parser, split_operands_normal) {
    auto operands = Parser::split_operands("add r1, r2, #1");
    ASSERT_EQ(operands.size(), 4);
    EXPECT_EQ(operands[0], "add");
    EXPECT_EQ(operands[1], "r1");
    EXPECT_EQ(operands[2], "r2");
    EXPECT_EQ(operands[3], "#1");
}

TEST(Parser, split_operands_long_spaces) {
    auto operands = Parser::split_operands("add     r1,      r2,     #1");
    ASSERT_EQ(operands.size(), 4);
    EXPECT_EQ(operands[0], "add");
    EXPECT_EQ(operands[1], "r1");
    EXPECT_EQ(operands[2], "r2");
    EXPECT_EQ(operands[3], "#1");
}

TEST(Parser, split_operands_no_commas) {
    auto operands = Parser::split_operands("add r1 r2 #1");
    ASSERT_EQ(operands.size(), 4);
    EXPECT_EQ(operands[0], "add");
    EXPECT_EQ(operands[1], "r1");
    EXPECT_EQ(operands[2], "r2");
    EXPECT_EQ(operands[3], "#1");
}

TEST(Parser, binary_conversion) {
    Parser parser(8);
    auto answer = parser.from_dec_to_binary("10");
    string str_answer = Parser::from_bin_to_string(answer);
    ASSERT_EQ(str_answer, "01010000");
}

TEST(Parser, bin_to_string_conversion) {
    bin arr = {0,1,0,0}; // NOLINT(modernize-use-bool-literals)
    cout << typeid(arr).name() << endl;
    ASSERT_EQ(Parser::from_bin_to_string(arr), "0100");
}

TEST(Parser, register_indices) {
    Parser parser(8);
    vector <string> operands = {"r1", "r2", "#1"};
    auto indices = parser.get_registers_indices(operands);

    ASSERT_EQ(indices.size(), 3);
    EXPECT_EQ(int(indices[0]), 1);
    EXPECT_EQ(int(indices[1]), 2);
    EXPECT_EQ(int(indices[2]), parser.NO_REGISTER);

}