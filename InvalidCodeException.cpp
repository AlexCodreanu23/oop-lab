#include "InvalidCodeException.h"


const char* InvalidCodeException::what() const noexcept {
    return "The code is negative!" ;
}