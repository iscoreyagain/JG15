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
```
## Resources

### Lexer & Parser
- [Crafting Interpreters (Chapters on Scanning & Parsing)](https://craftinginterpreters.com/)
- [Compiler Design – Lecture Notes](https://www.cs.princeton.edu/courses/archive/spr06/cos326/notes.html)

### Abstract Syntax Tree (AST)
- [AST Basics - Wikipedia](https://en.wikipedia.org/wiki/Abstract_syntax_tree)
- [Programming Language Pragmatics – Chapter on ASTs](https://www.pearson.com/en-us/subject-catalog/p/programming-language-pragmatics/P200000007828/9780123745149)

### Automata Theory
- [Introduction to Automata Theory, Languages, and Computation](https://www.amazon.com/Introduction-Automata-Theory-Languages-Computation/dp/0321455363)
- [Automata Theory - GeeksforGeeks](https://www.geeksforgeeks.org/introduction-of-finite-automata/)

