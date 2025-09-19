#include <gtest/gtest.h>
#include "pattern.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

// Test matching a digit
TEST(MatcherTest, DigitMatch) {
    string input = "apple5";
    string pattern_str = "\\d";
    auto tokens = parse(pattern_str);
    EXPECT_TRUE(match(input, tokens));
    EXPECT_FALSE(match("apple", tokens));
}

// Test literal character
TEST(MatcherTest, LiteralCharacter) {
    string input = "dog";
    string pattern_str = "d";
    auto tokens = parse(pattern_str);
    EXPECT_TRUE(match(input, tokens));
    EXPECT_FALSE(match("cat", tokens));
}

// Test positive group [abc]
TEST(MatcherTest, PositiveGroup) {
    string input = "bat";
    string pattern_str = "[abc]";
    auto tokens = parse(pattern_str);
    EXPECT_TRUE(match(input, tokens));  // matches 'b'
    
    EXPECT_FALSE(match("dog", tokens));
}

// Test negative group [^xyz]
TEST(MatcherTest, NegativeGroup) {
    string input = "dog";
    string pattern_str = "[^xyz]";
    auto tokens = parse(pattern_str);
    EXPECT_TRUE(match(input, tokens));  // 'd' is not x/y/z
    EXPECT_TRUE(match("xylophone", tokens));
    EXPECT_TRUE(match("abcx", tokens));
    EXPECT_FALSE(match("zyx", tokens));
}

// Test unterminated group: should throw
TEST(ParserErrorTest, UnterminatedPositiveGroup) {
    string bad_pattern = "[abc"; // missing closing ]
    EXPECT_THROW(parse(bad_pattern), std::runtime_error);
}

TEST(ParserErrorTest, UnterminatedNegativeGroup) {
    string bad_pattern = "[^abc"; // missing closing ]
    EXPECT_THROW(parse(bad_pattern), std::runtime_error);
}

// Test empty groups
TEST(MatcherTest, EmptyPositiveGroup) {
    string input = "anything";
    string pattern_str = "[]";  // empty group
    auto tokens = parse(pattern_str);
    EXPECT_FALSE(match(input, tokens));  // should always fail
}

TEST(MatcherTest, EmptyNegativeGroup) {
    string input = "abc";
    string pattern_str = "[^]";  // negated but empty set
    auto tokens = parse(pattern_str);
    EXPECT_TRUE(match(input, tokens));  // always succeeds
}