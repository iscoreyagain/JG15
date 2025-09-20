# JG15 - Mini Regex Engine
An educational + lightweight **regex engine implemented from scratch in C++**
## Features
* Tokenizes regex patterns (\d, \w, [abc], [^abc], literal characters, ^, $)

* Matches patterns against input strings using a **naive matcher** (supports sliding-window match)

* Modular design for **lexer**, **parser**, and **matcher**

* Ready for extension with **AST-based parsing** and **NFA/DFA construction**

* Handles character groups, anchors, and simple regex tokens

## Motivation
Regexes are everywhere in backend systems — from **log parsing**, **input validation**, to **query languages**.

This project was built to:
* Learn **C++** by implementing a non-trivial project from scratch

* Understand **regex internals** (lexer, parser, matching engine)

* Learn **modular design** for complex parsing and matching 

* Explore **performance and optimization trade-offs** (naive vs NFA/DFA)

## Usage
```bash
g++ -std=c++17 main.cpp pattern.cpp -o mini_regex
./mini_regex "a*(b|c)" "aaab"
# Output: Match found
