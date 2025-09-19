#include <gtest/gtest.h>

/* int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

#include <iostream>
#include <string>
#include "pattern.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " PATTERN\n";
        return 1;
    }

    std::string pattern_str = argv[1];
    auto tokens = parse(pattern_str);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (match(line, tokens)) {
            std::cout << line << "\n"; 
        }
    }

    return 0;
}