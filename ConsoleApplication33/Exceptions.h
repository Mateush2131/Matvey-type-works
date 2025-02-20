#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InsufficientFundsException : public std::runtime_error {
public:
    InsufficientFundsException(const std::string& message) : std::runtime_error(message) {}
};

class ProductNotFoundException : public std::runtime_error {
public:
    ProductNotFoundException(const std::string& message) : std::runtime_error(message) {}
};

class InsufficientStockException : public std::runtime_error {
public:
    InsufficientStockException(const std::string& message) : std::runtime_error(message) {}
};

#endif