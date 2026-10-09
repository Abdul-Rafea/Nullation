#pragma once

// Structures
struct Error {
    int severity; // 1 = low, 2 = svere
    const char* type;
    const char* message;
};

// Function Prototypes
void setNewError(Error& error, Error*& errors, int& errorsSize);
void printErrors(const Error* errors, const int& errorsSize);