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
		return true ;
	else
		return false;
}

int	RPN::performOperation(int first, int second, const std::string &op) const {
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
	std::string number;

	for (size_t i = 0; i < expression.size(); ++i) {
		char c = expression[i];
		if (isdigit(c)) {
			number += c;
		} else if (c == ' ' && !number.empty()) {
			_stack.push(std::stof(number));
			number.clear();
		} else if (CheckOperator(c)) {
			if (_stack.size() < 2) {
				std::cout << "Error: impossible to perform the operation." << std::endl;
				return;
			}
			float second = _stack.top();
			_stack.pop();
			float first = _stack.top();
			_stack.pop();
			try {
				float result = performOperation(first, second, std::string(1, c));
				_stack.push(result);
			} catch (const RPNException& e) {
				std::cout << e.what() << std::endl;
				return;
			}
		} else if (c != ' ') {
			std::cout << "Error: Invalid character: '" << c << "'" << std::endl;
			return;
		}
	}
	if (_stack.size() != 1) {
		std::cout << "Error: incomplete expression." << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}

RPN::~RPN(){}