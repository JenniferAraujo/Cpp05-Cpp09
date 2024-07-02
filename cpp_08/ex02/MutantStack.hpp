#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <limits>
#include <stack>
#include <algorithm>
#include <exception>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack& copy) : std::stack<T, Container>(copy) {}
	~MutantStack(){}
	MutantStack& operator=(const MutantStack& copy) {
        if (this != &copy)
            std::stack<T, Container>::operator=(copy);
        return *this;
    }

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
