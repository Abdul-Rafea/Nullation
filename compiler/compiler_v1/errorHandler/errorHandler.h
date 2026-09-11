#pragma once

#include <string>

// ANSI color codes
inline const std::string RESET = "\033[0m";
inline const std::string BLUE = "\033[34m";
inline const std::string GREEN = "\033[32m";
inline const std::string YELLOW = "\033[33m";
inline const std::string RED = "\033[31m";

enum class ErrorCode {
    // Cli Errors
    COMMAND_ERROR = 100,
    FIlENAME_ERROR = 101,

    // Lever Errors
};

class Error {
    private:    
        ErrorCode code;
        std::string message;
        size_t line;
        size_t column;
    public:
        Error(ErrorCode Code, std::string Message);
        Error(ErrorCode Code, std::string Message, int Line, int Column);
        
        void print();
};