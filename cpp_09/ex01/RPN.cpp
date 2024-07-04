#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& copy){
    *this = copy;
}

RPN& RPN::operator=(const RPN& copy){
    if (this != &copy){
    }
    return *this;
}

RPN::~RPN(){}