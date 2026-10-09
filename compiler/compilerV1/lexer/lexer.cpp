#include <fstream>

#include "lexer.h"

Token* runLexer(char* filename, Error*& errors, int& errorsSize, int& tokensSize) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        Error error = {
            2,
            "File Not Found",
            "Unable to open the file, make sure file is in src folder"
        };
        setNewError(error, errors, errorsSize);
        return;
    }

    char letter;
    tokensSize++;
    Token* tokens = new Token[tokensSize];
    while(file.get(letter)) {
        Token& token = tokens[tokensSize - 1]; // alias

        if(letter == ' ') {
            if(token.lettersSize > 0) {
                tokensSize++;
                Token* newTokens = new Token[tokensSize];
                for(int i = 0; i < tokensSize - 1; i++) {
                    newTokens[i] = tokens[i];
                }
                delete[] tokens;
                tokens = newTokens;
            }
            continue;
        }

        token.lettersSize++; // increasing array size
        char* newCharArray = new char[token.lettersSize]; // creating new array
        for(int i = 0; i < token.lettersSize - 1; i++) { // copying old array
            newCharArray[i] = token.letters[i];
        }
        newCharArray[token.lettersSize - 1] = letter; // setting new character
        if(token.lettersSize - 1 != 0) {
            delete[] token.letters; // deleting old array
        }
        token.letters = newCharArray; // pointing to new array
    }

    return tokens;
}

void printTokens(const Token* tokens, int tokensSize)