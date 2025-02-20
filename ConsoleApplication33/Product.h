#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    int id;
    std::string name;
    std::string description;

public:
    Product(int id, const std::string& name, const std::string& description);

    int getId() const;
    std::string getName() const;
    std::string getDescription() const;

    void displayProductInfo() const;
    bool operator==(const Product& other) const;
};

#endif#pragma once
