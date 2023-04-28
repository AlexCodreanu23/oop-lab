#include <exception>

class NoTitleException : public std::exception {
public:
    NoTitleException() = default;

    const char* what() const noexcept override  {
        return "Empty title";
    }
};