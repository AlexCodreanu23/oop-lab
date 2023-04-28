#ifndef _InvalidCodeException_H_
#define _InvalidCodeException_H_

#include <exception>

class InvalidCodeException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif