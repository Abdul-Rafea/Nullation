#include <iostream>
#include <string>
#include <fstream>


// Custom Header Files
#include "lexer.h"

std::vector<Token> lexer(std::string file_name) {
    //Open File
    std::ifstream file(file_name);

    // Does File Exists
    if(!file.is_open()) {
        std::cout << "Incorrect File Name";
        return;
    }

    while(!file.eof()) {
        Token token;

        file >> token.value;

        // Check For Reserved Words
        for(int i = 0; i < RESERVED_WORDS.size(); i++) {
            if(token.value == RESERVED_WORDS.at(i)) {
                
            }
        }
    }
}