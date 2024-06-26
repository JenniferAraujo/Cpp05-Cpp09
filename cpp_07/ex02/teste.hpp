// Array.hpp

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // for std::out_of_range
#include <algorithm> // for std::copy

template <typename T>
class Array {
private:
    T* m_data;
    size_t m_size;

public:
    // Constructor without parameters: creates an empty array
    Array() : m_data(nullptr), m_size(0) {}

    // Constructor with a parameter n: creates an array of n elements initialized by default
    explicit Array(size_t n) : m_data(new T[n]), m_size(n) {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = T(); // Default initialization
        }
    }

    // Copy constructor
    Array(const Array& other) : m_data(new T[other.m_size]), m_size(other.m_size) {
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            // Deallocate current memory
            delete[] m_data;

            // Allocate new memory and copy elements
            m_size = other.m_size;
            m_data = new T[m_size];
            std::copy(other.m_data, other.m_data + m_size, m_data);
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] m_data;
    }

    // Subscript operator for element access
    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return m_data[index];
    }

    // Member function to return the size of the array
    size_t size() const {
        return m_size;
    }
};

#endif // ARRAY_HPP
