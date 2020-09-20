//
// Created by rony on 20.09.20.
//
#include "gtest/gtest.h"
#include "Parser.h"

TEST(Parser, split1) {
    ASSERT_EQ(Parser::contains_splitters(' '), true);
}