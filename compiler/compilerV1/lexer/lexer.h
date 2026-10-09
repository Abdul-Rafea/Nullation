#pragma once

#include "../errorHandler/errorHandler.h"

// Structures
struct Token {
    int lettersSize = 0;
    char* letters;
};


// Function Prototypes
Token* runLexer(char* filename, Error*& errors, int& errorsSize);
// void runLexer(char* filename, Error*& errors, int& errorsSize);

