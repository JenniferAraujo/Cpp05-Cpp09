#include "includes/InvalidOptionException.hpp"

const char* InvalidOptionException::what() const throw(){
    return "\033[1;31mInvalid option!\033[0m";
}
