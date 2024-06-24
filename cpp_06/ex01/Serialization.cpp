#include "Serialization.hpp"

Serialization::Serialization()
{
	std::cout << BLUE << "Serialization default constructor called" << RESET << std::endl;
}

Serialization::Serialization(const Serialization& copy)
{
	std::cout << BLUE << "Serialization copy constructor called" << RESET << std::endl;
	*this = copy;
}

Serialization& Serialization::operator=(const Serialization& copy)
{
	if (this == &copy)
		return *this;
	std::cout << BLUE << "Serialization copy assignment operator overload" << RESET << std::endl;
	return *this;
}

uintptr_t	Serialization::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

Serialization::~Serialization()
{
	std::cout << BLUE << "Serialization default constructor called" << RESET << std::endl;
}
