#include "Store.h"
#include "Exceptions.h"
#include "Customer.h" // Добавляем Customer.h
#include <iostream>

Store::Store(int id, const std::string& name, const std::string& address) :
    id(id), name(name), address(address) {}

int Store::getId() const {
    return id;
}

std::string Store::getName() const {
    return name;
}

std::string Store::getAddress() const {
    return address;
}

int Store::getProductQuantity(const Product& product) const {
    auto it = inventory.find(product);
    if (it != inventory.end()) {
        return it->second.first;
    }
    else {
        return 0;
    }
}

double Store::getProductPrice(const Product& product) const {
    auto it = inventory.find(product);
    if (it != inventory.end()) {
        return it->second.second;
    }
    else {
        return 0.0;
    }
}

void Store::addProduct(const Product& product, int quantity, double price) {
    if (quantity <= 0 || price <= 0) {
        throw std::invalid_argument("Quantity and price must be positive.");
    }
    inventory[product] = std::make_pair(quantity, price);
    std::cout << "Added product " << product.getName() << " to store " << name << std::endl;
}

void Store::removeProduct(const Product& product) {
    auto it = inventory.find(product);
    if (it != inventory.end()) {
        inventory.erase(it);
        std::cout << "Removed product " << product.getName() << " from store " << name << std::endl;
    }
    else {
        std::cout << "Product " << product.getName() << " not found in store " << name << std::endl;
    }
}

void Store::updateProductQuantity(const Product& product, int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("Quantity must be non-negative.");
    }
    auto it = inventory.find(product);
    if (it != inventory.end()) {
        it->second.first = quantity;
        std::cout << "Updated quantity of product " << product.getName() << " in store " << name << std::endl;
    }
    else {
        std::cout << "Product " << product.getName() << " not found in store " << name << std::endl;
    }
}

void Store::updateProductPrice(const Product& product, double price) {
    if (price <= 0) {
        throw std::invalid_argument("Price must be positive.");
    }
    auto it = inventory.find(product);
    if (it != inventory.end()) {
        it->second.second = price;
        std::cout << "Updated price of product " << product.getName() << " in store " << name << std::endl;
    }
    else {
        std::cout << "Product " << product.getName() << " not found in store " << name << std::endl;
    }
}

void Store::displayInventory() const {
    std::cout << "Inventory of store " << name << ":" << std::endl;
    for (const auto& item : inventory) {
        std::cout << "  " << item.first.getName() << ": Quantity = " << item.second.first
            << ", Price = " << item.second.second << std::endl;
    }
}

bool Store::sellProduct(Customer& customer, const Product& product, int quantity) {
    if (quantity <= 0) {
        throw std::invalid_argument("Quantity must be positive.");
    }

    auto it = inventory.find(product);
    if (it == inventory.end()) {
        throw ProductNotFoundException("Product " + product.getName() + " not found in store " + name);
    }

    if (it->second.first < quantity) {
        throw InsufficientStockException("Insufficient stock of product " + product.getName() + " in store " + name);
    }

    double totalPrice = it->second.second * quantity;
    if (customer.getBalance() < totalPrice) {
        throw InsufficientFundsException("Insufficient funds for customer " + customer.getFirstName());
    }

    try {
        customer.deductFunds(totalPrice);
        it->second.first -= quantity;
        std::cout << "Customer " << customer.getFirstName() << " purchased " << quantity << " of "
            << product.getName() << " from store " << name << " for $" << totalPrice << std::endl;
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "Transaction failed: " << e.what() << std::endl;
        return false;
    }
}