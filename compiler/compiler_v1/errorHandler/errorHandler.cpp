#include<iostream>

#include<string>

// Custom Header Files
#include "errorHandler.h"

Error::Error(ErrorCode Code, std::string Message) {
    code = Code;
    message = Message;
}

Error::Error(ErrorCode Code, std::string Message, int Line, int Column) {
    code = Code;
    message = Message;
    line = Line;
    column = Column;
}

void Error::print() {
    if(code == ErrorCode::COMMAND_ERROR || code == ErrorCode::FIlENAME_ERROR) {
        std::cout << RED;
        std::cout << "Error " << "[" << int(code) << "]:";

        if(code == ErrorCode::COMMAND_ERROR) {
            std::cout << "COMMAND_ERROR";
        }
        else if(code == ErrorCode::FIlENAME_ERROR) {
            std::cout << "FILENAME_ERROR";
        }

        std::cout << std::endl;
        std::cout << "-> " << message << std::endl;
        std::cout << RESET;
    }
}