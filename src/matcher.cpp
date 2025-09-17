#include <grep/matcher.h>
#include <stdexcept>

bool match_pattern(const std::string& input_line, const std::string& pattern) {
    if(pattern.length() == 1) {
        return input_line.find(pattern) != std::string::npos;
    } else {
        throw std::runtime_error("Unhandled pattern " + pattern);
    }
}

