//
// Created by rony on 20.09.20.
//
#include "gtest/gtest.h"
#include "Parser.h"
#include "Processor.h"


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

//divide_dec_by_two tests
TEST(Parser, t0) {
    longArith res;
    int rem;
    Parser::divide_dec_by_two(longArith({0}), res, rem);
    ASSERT_EQ(longArith({0}), res);
    ASSERT_EQ(0, rem);
}

TEST(Parser, t1) {
    longArith res;
    int rem;
    Parser::divide_dec_by_two(longArith({1}), res, rem);
    ASSERT_EQ(longArith({0}), res);
    ASSERT_EQ(1, rem);
}

TEST(Parser, t2) {
    longArith res;
    int rem;
    Parser::divide_dec_by_two(longArith({2}), res, rem);
    ASSERT_EQ(longArith({1}), res);
    ASSERT_EQ(0, rem);
}

TEST(Parser, t7) {
    longArith res;
    int rem;
    Parser::divide_dec_by_two(longArith({7}), res, rem);
    ASSERT_EQ(longArith({3}), res);
    ASSERT_EQ(1, rem);
}

TEST(Parser, t145) {
    longArith res;
    int rem;
    Parser::divide_dec_by_two(longArith({145}), res, rem);
    ASSERT_EQ(longArith({72}), res);
    ASSERT_EQ(1, rem);
}

TEST(Parser, t140005) {
    longArith res;
    int rem;
    Parser::divide_dec_by_two(longArith({140005}), res, rem);
    ASSERT_EQ(longArith({70002}), res);
    ASSERT_EQ(1, rem);
}