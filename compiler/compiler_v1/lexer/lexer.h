#pragma once

#include <string>
#include <vector>

struct Token {
    std::string value;
    std::string type;
};

const std::vector<std::string> RESERVED_WORDS = {
    "int",
    "float",
    "char",
    "bool"
};