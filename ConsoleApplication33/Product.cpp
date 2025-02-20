#include "Product.h"

Product::Product(int id, const std::string& name, const std::string& description) :
    id(id), name(name), description(description) {}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

std::string Product::getDescription() const {
    return description;
}

void Product::displayProductInfo() const {
    std::cout << "Product ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
}

bool Product::operator==(const Product& other) const {
    return id == other.id;
}