#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
# include <limits>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
# include <ctime>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

template <typename T>
class Array {
	private:
		unsigned int _size;
		T* _data;
	public: 
		Array();
		Array(unsigned int n); //Construction with an unsigned int n as a parameter
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		T & operator[](unsigned int index); // operator: [ ]

		class	InvalidIndexException : public std::exception {
		public:
			virtual const char	*what() const throw();
		};

		unsigned int size(void) const; //size array
		~Array();
};

template<typename T>
Array<T>::Array(): _size(0)
{
	_data = new T[0]();
}

template<typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	_data = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& copy): _size(copy._size)
{
	_data = NULL;
	*this = copy;
}

template<typename T>
Array<T> & Array<T>::operator=(const Array& copy)
{
	if (_data != NULL)
		delete [] _data;
	_size = copy._size;
	_data = new T[_size]();
	for (unsigned int i = 0; i < copy._size; i++)
		_data[i] = copy._data[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size || _data == NULL)
		throw Array<T>::InvalidIndexException();
	return _data[index];
}

template<typename T>
Array<T>::~Array(){
	if (_data != NULL)
		delete [] _data;
}

template<typename T>
const char	*Array<T>::InvalidIndexException::what() const throw(){
	return "Ops, index is out of bounds";
}

template<typename T>
unsigned int Array<T>::size(void) const{
	return _size;
}

#endif

