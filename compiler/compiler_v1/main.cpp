#include <iostream>
#include <string>

// Custom Header Files
#include "lexer/lexer.h"

void run(std::string) {
}

int main() {
    // Cli
    while(true) {
        std::string command;
        std::string file_name;

        std::cin >> command >> file_name;

        if(command == "run") {
            run(file_name);
        }

    }
}