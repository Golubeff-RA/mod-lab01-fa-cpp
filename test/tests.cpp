// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "fun.h"

TEST(task1, test1) {
    const char* str = "qwe4  gftt e 555gr rrgr  grhh ";
    unsigned int result = faStr1(str);
    EXPECT_EQ(4, result);
}

TEST(task1, test2) {
    const char* str = "  qwe4 ";
    unsigned int result = faStr1(str);
    EXPECT_EQ(0, result);
}

TEST(task2, test3) {
    const char* str = "Hello, world!";
    unsigned int result = faStr2(str);
    EXPECT_EQ(0, result);
}

TEST(task2, test4) {
    const char* str = "Hello world!";
    unsigned int result = faStr2(str);
    EXPECT_EQ(1, result);
}

TEST(task3, test5) {
    const char* str = " bad dog ";
    unsigned int result = faStr3(str);
    EXPECT_EQ(3, result);
}

TEST(task3, test6) {
    const char* str = " six monkeys";
    unsigned int result = faStr3(str);
    EXPECT_EQ(5, result);
}

TEST(faStr1Test, EmptyString) {
    EXPECT_EQ(faStr1(""), 0);
}

TEST(faStr1Test, OnlySpaces) {
    EXPECT_EQ(faStr1("  "), 0);
}

TEST(faStr1Test, SingleWordNoDigits) {
    EXPECT_EQ(faStr1("abc"), 1);
}

TEST(faStr1Test, SingleWordWithDigits) {
    EXPECT_EQ(faStr1("123"), 0);
}

TEST(faStr1Test, MultipleWordsNoDigits) {
    EXPECT_EQ(faStr1("Hello world test"), 3);
}

TEST(faStr1Test, MultipleWordsWithDigits) {
    EXPECT_EQ(faStr1("Hello world 123 test"), 3);
}

TEST(faStr1Test, LeadingAndTrailingSpaces) {
    EXPECT_EQ(faStr1("  Hello world test  "), 3);
}

TEST(faStr1Test, MultipleSpacesBetweenWords) {
    EXPECT_EQ(faStr1("Hello   world   test"), 3);
}

TEST(faStr1Test, MixedWordsAndDigits) {
    EXPECT_EQ(faStr1("abc def123 ghi"), 2);
}

TEST(faStr1Test, EdgeCaseWithOnlyDigitWord) {
    EXPECT_EQ(faStr1(" word1 "), 0);
    EXPECT_EQ(faStr1(" 1word "), 0);
}

TEST(faStr2Test, EmptyString) {
    EXPECT_EQ(faStr2(""), 0);
}

TEST(faStr2Test, OnlySpaces) {
    EXPECT_EQ(faStr2("  "), 0);
}

TEST(faStr2Test, SingleWordValid) {
    EXPECT_EQ(faStr2("Abc"), 1);
}

TEST(faStr2Test, SingleWordInvalid) {
    EXPECT_EQ(faStr2("abc"), 0);
}

TEST(faStr2Test, MultipleWordsValid) {
    EXPECT_EQ(faStr2("Hello world Test"), 2);
}

TEST(faStr2Test, MultipleWordsInvalid) {
    EXPECT_EQ(faStr2("hello world test"), 0);
}

TEST(faStr2Test, LeadingAndTrailingSpaces) {
    EXPECT_EQ(faStr2("  Hello world Test  "), 2);
}

TEST(faStr2Test, MultipleSpacesBetweenWords) {
    EXPECT_EQ(faStr2("Hello   world   Test"), 2);
}

TEST(faStr2Test, MixedWords) {
    EXPECT_EQ(faStr2("Abc def Ghi"), 2);
}

TEST(faStr2Test, WordsWithDigits) {
    EXPECT_EQ(faStr2("Abc1 def Ghi"), 1);
}

TEST(faStr2Test, OnlyUpperCase) {
    EXPECT_EQ(faStr2("ABC"), 0);
}

TEST(faStr2Test, MixedCase) {
    EXPECT_EQ(faStr2("AbCd"), 0);
}

TEST(faStr2Test, MoreValidWords) {
    EXPECT_EQ(faStr2("Abc Def Ghi"), 3);
}

TEST(faStr3Test, EmptyString) {
    EXPECT_EQ(faStr3(""), 0);
}

TEST(faStr3Test, OnlySpaces) {
    EXPECT_EQ(faStr3("  "), 0);
}

TEST(faStr3Test, SingleWord) {
    EXPECT_EQ(faStr3("abc"), 3);
}

TEST(faStr3Test, MultipleWordsSameLength) {
    EXPECT_EQ(faStr3("Hello world Test"), 5);
}

TEST(faStr3Test, MultipleWordsDifferentLength) {
    EXPECT_EQ(faStr3("Hello world test"), 5);
}

TEST(faStr3Test, LeadingAndTrailingSpaces) {
    EXPECT_EQ(faStr3("  Hello world Test  "), 5);
}

TEST(faStr3Test, MultipleSpacesBetweenWords) {
    EXPECT_EQ(faStr3("Hello   world   Test"), 5);
}

TEST(faStr3Test, VeryLongAndShortWords) {
    EXPECT_EQ(faStr3("a verylongword"), 7);
}

TEST(faStr3Test, AllEmptyWords) {
    EXPECT_EQ(faStr3("   "), 0);
}

TEST(faStr3Test, Test1) {
    EXPECT_EQ(faStr3("ab"), 2);
}
TEST(faStr3Test, Test2) {
    EXPECT_EQ(faStr3("abc def"), 3);
}

TEST(faStr3Test, Test3) {
    EXPECT_EQ(faStr3("abcd defghijk"), 6);
}
