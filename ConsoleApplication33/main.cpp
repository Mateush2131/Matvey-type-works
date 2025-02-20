#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Store.h"
#include "Exceptions.h"
#include <limits>

int main() {
    Product apple(1, "Apple", "A crisp and delicious fruit");
    Product banana(2, "Banana", "A yellow and nutritious fruit");
    Product milk(3, "Milk", "Fresh and creamy milk");

    Customer customer(101, "Alice", "Smith", 100.0);

    Store store(201, "Fresh Foods Market", "123 Main St");

    try {
        store.addProduct(apple, 10, 1.0);
        store.addProduct(banana, 20, 0.5);
        store.addProduct(milk, 5, 3.0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error adding product: " << e.what() << std::endl;
    }

    store.displayInventory();

    try {
        store.sellProduct(customer, apple, 3);
        store.sellProduct(customer, banana, 5);
    }
    catch (const InsufficientFundsException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const ProductNotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const InsufficientStockException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    customer.displayCustomerInfo();

    store.displayInventory();

    try {
        store.removeProduct(milk);
    }
    catch (const std::exception& e) {
        std::cerr << "Error removing product: " << e.what() << std::endl;
    }

    store.displayInventory();

    return 0;
}