#include <iostream>

#include "errorHandler.h"
#include "../util/util.h"

void setNewError(Error& error, Error*& errors, int& errorsSize) {
    errorsSize++; // increasing size
    Error* newErrors = new Error[errorsSize]; // creating new array
    for(int i = 0; i < errorsSize - 1; i++) { // copying old array
        newErrors[i] = errors[i];
    }
    newErrors[errorsSize - 1] = error; // setting new element 
    if(errorsSize - 1 != 0) {
        delete[] errors; // deleting old array
    }
    errors = newErrors; // pointing to new array
}

void printErrors(const Error* errors, const int& errorsSize) {
    std::cout << std::endl << errorsSize << "Errors Found: -" << std::endl;
    for(int i = 0; i < errorsSize; i++) {
        std::cout << "  -> " << errors[i].type << " : " << errors[i].message << std::endl;
    }
}