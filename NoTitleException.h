#ifndef _NoTitleException_H_
#define _NoTitleException_H_
#include <exception>
#include  "book.h"

class NoTitleException:public std::exception{

private:
    const char *message;
public:
    NoTitleException(const char* message) : message(message) {}
    virtual const char* what() const noexcept override;


};









#endif