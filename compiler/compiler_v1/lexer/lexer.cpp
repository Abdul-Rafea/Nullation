
// Custom Header Files
#include "lexer.h"

Lexer::Lexer(const std::string& fileName, std::vector<Error>& Errors) 
    : errors(Errors) {

    std::ifstream file(fileName);

    if(!file.is_open()) {
        Error error(ErrorCode::FIlENAME_ERROR, "Cannot open this file, wrong filename or directory");
        errors.push_back(error);
    }
}