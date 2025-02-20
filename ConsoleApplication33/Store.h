#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include <map>
#include "Product.h"
#include <iostream>
#include "Exceptions.h"

class Store {
private:
    int id;
    std::string name;
    std::string address;
    std::map<Product, std::pair<int, double>> inventory;

public:
    Store(int id, const std::string& name, const std::string& address);

    int getId() const;
    std::string getName() const;
    std::string getAddress() const;
    int getProductQuantity(const Product& product) const;
    double getProductPrice(const Product& product) const;

    void addProduct(const Product& product, int quantity, double price);
    void removeProduct(const Product& product);
    void updateProductQuantity(const Product& product, int quantity);
    void updateProductPrice(const Product& product, double price);
    void displayInventory() const;

    bool sellProduct(Customer& customer, const Product& product, int quantity);
};

#endif