#include <pattern_token.h>
#include <vector>
#include <unordered_set>

// echo -n "dog" | ./[some-file].sh -E "\d"
// pattern = "\\d"
vector<PatternToken> parse(const std::string& pattern) {
    size_t idx = 0;
    vector<PatternToken> store;
    size_t len = pattern.size();

    while(idx < len) {
        if(idx + 1 < len && pattern[idx] == '\\' && pattern[idx + 1] == 'd') {
            PatternToken tok;
            tok.Type = Digit;
            store.emplace_back(tok);
            idx += 2;
        } else if(idx + 1 < len && pattern[idx] == '\\' && pattern[idx + 1] == 'w') {
            PatternToken tok;
            tok.Type = AlphaNumeric;
            store.emplace_back(tok);
            idx += 2;
        } else {
            PatternToken tok;
            tok.Type = Character;
            store.emplace_back(tok);
            idx += 2;
        }
    }

    return store;
}