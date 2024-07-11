#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& copy) {
	while (!_stack.empty())
		_stack.pop();
	*this = copy;
}

RPN& RPN::operator=(const RPN& copy) {
	while (!_stack.empty())
		_stack.pop();
	_stack = copy._stack;
	return *this;
}

RPN::RPNException::RPNException(const std::string& message) : _message(message) {}

const char*	RPN::RPNException::what() const throw(){
	return _message.c_str();
}

bool	RPN::CheckOperator(char op) {
	if (op == '+' ||  op == '-' || op == '*' || op == '/')
		return true;
	else 
		return false;
}

bool	RPN::invalidChar(char c) {
	if ((c >= '0' && c <= '9') || c == ' ' || CheckOperator(c) == true)
		return false ;
	else
		return true;
}

float	RPN::performOperation(float first, float second, const std::string &op) const {
	if (op == "+")
		return first + second;
	if (op == "-")
		return first - second;
	if (op == "*")
		return first * second;
	if (op == "/") {
		if (second == 0)
			throw RPNException("Error: division by zero.");
		return first / second;
	}
	throw RPNException("Error: invalid operator.");
}

void	RPN::calculate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string op;
	while (iss >> op) {
		if (isdigit(op[0])) {
			_stack.push(std::atof(op.c_str()));
		} else if (invalidChar(op[0])) {
			std::cout << "Error: Invalid character: '" << op << "'" << std::endl;
			return;
		} else if (CheckOperator(op[0])) {
			if (_stack.size() < 2) {
				std::cout << "Error: impossible to perform the operation." << std::endl;
				return ;
			}
			float second = _stack.top();
			_stack.pop();
			float first = _stack.top();
			_stack.pop();
			try {
				float result = performOperation(first, second, op);
				_stack.push(result);
			} catch (const RPNException& e) {
				std::cout << e.what() << std::endl;
				return ;
			}
		}
	}
	if (_stack.size() != 1) {
		std::cout << "Error: Incomplete expression." << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}

RPN::~RPN(){}