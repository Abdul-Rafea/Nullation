#include <iostream>
#include <cstring>

#include "lexer/lexer.h"
#include "errorHandler/errorHandler.h"

// Functions Prototypes
void run(char* filename, Error*& errors, int& errorsSize) {
    Token* tokens = nullptr;
    int tokensSize = 0;
    tokens = runLexer(filename, errors, errorsSize, tokensSize);
}

int main() {
    int errorsSize = 0;
    Error* errors = nullptr;

    // Cli
    while(true) {
        char command[100];
        char filename[200];
        char filePath[] = "src/";
        std::cout << "Enter Command: ";
        std::cin >> command >> filename;

        if(std::strcmp(command, "run") == 0) {
            run(std::strcat(filePath, filename), errors, errorsSize);
        }
        else {
            Error error = {
                2,
                "Inalid Command",
                "The command you entred does not match any operation"
            };
            setNewError(error, errors, errorsSize);
        }

        if(errorsSize > 0) {
            printErrors(errors, errorsSize);
        }
    }

    delete[] errors;
}