#include "pattern.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_set;
// echo -n "dog" | ./[some-file].sh -E "\d"
// pattern = "\\d"

// argc[0] = "./[some_file].sh"
// argc[1] = "-E"
// argc[2] = "\\d" ==> pattern

// The use of the parser is to parse the end of CLI's result and convert it in our own struct (PatternToken)
vector<PatternToken> parse(const std::string& pattern) {
    size_t idx = 0;
    vector<PatternToken> store;
    size_t len = pattern.size();

    while(idx < len) {
        if(idx + 1 < len && pattern[idx] == '\\' && pattern[idx + 1] == 'd') {
            PatternToken tok;
            tok.type = TokenType::Digit;
            store.emplace_back(tok);
            idx += 2;
        } else if(idx + 1 < len && pattern[idx] == '\\' && pattern[idx + 1] == 'w') {
            PatternToken tok;
            tok.type = TokenType::AlphaNumeric;
            store.emplace_back(tok);
            idx += 2;
        } else if(idx + 1 < len && pattern[idx] == '[' && pattern[idx + 1] != '^') {
            unordered_set<char> positive;
            idx++;
            while(idx < len && pattern[idx] != ']') {
                positive.insert(pattern[idx]);
                idx++;
            }

            if(idx == len) {
                throw std::runtime_error("You forgot to unterminate the ']' !!");
            }
            // Reach the end of the pattern
            PatternToken tok;
            tok.type = TokenType::PositiveGroup;
            if(!positive.empty()) {
                tok.positiveCharGroup = positive;
            } else {
                tok.positiveCharGroup = {};
            }
            store.emplace_back(tok);
            idx++;
        } else if(idx + 1 < len && pattern[idx] == '[' && pattern[idx + 1] == '^') {
            unordered_set<char> negative;
            idx += 2; //Pass through '[' and '^'
            while(idx < len && pattern[idx] != ']') {
                negative.insert(pattern[idx]);
                idx++;
            }

            if(idx == len) {
                throw std::runtime_error("You forgot to unterminate the ']' !!");
            }

            // Reach the end of the pattern
            PatternToken tok;
            tok.type = TokenType::NegativeGroup;
            if(!negative.empty()) {
                tok.negativeCharGroup = negative;
            } else {
                tok.negativeCharGroup = {};
            }
            store.emplace_back(tok);
            idx++;
        } else {
            PatternToken tok;
            tok.type = TokenType::Character;
            tok.character = pattern[idx];
            store.emplace_back(tok);
            idx++;
        }
    }

    return store;
}

/*bool match_pattern(const string& input_line, const string& pattern) {
    if(pattern.length() == 1) {
        return input_line.find(pattern) != std::string::npos;
    } else if (pattern == "\\d") {
        return input_line.find_first_of("0123456789") != std::string::npos;
    } else if (pattern == "\\w") {
        return input_line.find_first_of("\\a-zA-z0-9_") != std::string::npos;
    } else {
        throw std::runtime_error("Unhandled pattern " + pattern);
    }
} */

bool match_token(const char& ch, const PatternToken& token) {
    switch (token.type) {
        case TokenType::Digit:
            return isdigit(static_cast<unsigned char>(ch));
        case TokenType::AlphaNumeric:
            return isalnum(static_cast<unsigned char>(ch));
        case TokenType::Character:
            return ch == token.character;
        case TokenType::PositiveGroup:
            if(token.positiveCharGroup.empty()) {
                return false;
            }
            return token.positiveCharGroup.count(ch) > 0;
        case TokenType::NegativeGroup:
            if(token.negativeCharGroup.empty()) {
                return true;
            }
            return token.negativeCharGroup.count(ch) == 0;
    }
    return false; 
}

bool match(const string& input_line, const vector<PatternToken> &tokens) {
    if(tokens.empty()) {
        return false;
    }

    size_t pattern_len = tokens.size();
    size_t input_len = input_line.size();

    for(int start = 0; start + pattern_len <= input_len; start++) {
        size_t idx = 0;
        bool failed = false;

        while(idx < pattern_len) {
            const auto& token = tokens[idx];
            const char& c = input_line[start + idx];
            
            if(!match_token(c, token)) {
                failed = true;
                break;
            }
            idx++;
        }

        if(!failed && idx == pattern_len) {
            return true;
        }
    }

    return false;
}