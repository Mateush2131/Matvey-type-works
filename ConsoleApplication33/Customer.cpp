#include "Customer.h"
#include <iostream>
#include <stdexcept>

Customer::Customer(int id, const std::string& firstName, const std::string& lastName, double initialBalance) :
    id(id), firstName(firstName), lastName(lastName), balance(initialBalance) {}

int Customer::getId() const {
    return id;
}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getLastName() const {
    return lastName;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::addFunds(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Amount must be positive.");
    }
    balance += amount;
    std::cout << "Added " << amount << " to balance. New balance: " << balance << std::endl;
}

bool Customer::deductFunds(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Amount must be positive.");
    }
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Deducted " << amount << " from balance. New balance: " << balance << std::endl;
        return true;
    }
    else {
        return false;
    }
}

void Customer::displayCustomerInfo() const {
    std::cout << "Customer ID: " << id << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}