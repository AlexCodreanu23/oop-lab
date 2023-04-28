#include "NoTitleException.h"

const char* NoTitleException::what() const noexcept {
    return message;
}