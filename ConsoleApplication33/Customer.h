#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <stdexcept>

class Customer {
private:
    int id;
    std::string firstName;
    std::string lastName;
    double balance;

public:
    Customer(int id, const std::string& firstName, const std::string& lastName, double initialBalance);

    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    double getBalance() const;

    void addFunds(double amount);
    bool deductFunds(double amount);
    void displayCustomerInfo() const;
};

#endif
