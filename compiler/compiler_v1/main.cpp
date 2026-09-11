#include <iostream>

#include <string>
#include <vector>

// Custom Header Files
#include "lexer/lexer.h"
#include "errorHandler/errorHandler.h"

void run(std::string) {

}

int main() {
    std::vector<Error> errors;

    // Cli
    while(true) {
        std::string command;
        std::string fileName;

        std::cin >> command >> fileName;

        if(command == "run") {
            run(fileName);
        }
        else {
            Error error(ErrorCode::COMMAND_ERROR, "Command does not match an operation");
            errors.push_back(error);
        }

        if(!errors.empty()) {
            for(int i = 0; i < errors.size(); i++) {
                errors.at(i).print();
            }
        }
    }
}