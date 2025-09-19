#pragma once
#include <string>
#include <vector>
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

bool match(const std::string& input_line,
           const std::vector<PatternToken>& tokens);
bool match_token(char& ch, const PatternToken& token); 
std::vector<PatternToken> parse(const std::string& pattern);