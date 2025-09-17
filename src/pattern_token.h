#pragma once
#include <unordered_set>

enum class TokenType {
  Digit,
  AlphaNumeric,
  Character,
  PositiveGroup,
  NegativeGroup,
};

struct PatternToken {
  TokenType type;
  char character = '\0';
  std::unordered_set<char> positiveCharGroup;
  std::unordered_set<char> negativeCharGroup;
};
