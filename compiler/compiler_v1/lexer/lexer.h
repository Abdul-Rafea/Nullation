#pragma once

#include <sstream>
#include <iostream>
#include <fstream>

#include <string>
#include <array>
#include <vector>

// Custom Header Files
#include "../errorHandler/errorHandler.h"

// Structures
struct Token {
    std::string value;
    std::string type;
};

// Main Class
class Lexer {
    private:
        std::vector<Error>& errors;
        std::stringstream buffer;
        size_t line;
        size_t column;
    public:
        Lexer(const std::string& fileName, std::vector<Error>& Errors);
};

// Const Data 
inline const std::array<std::string, 5> KEYWORDS {
    "int",
    "float",
    "char",
    "bool"
};
