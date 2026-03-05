#include "Warehouse.h"
#include <iostream>
#include <iomanip>

Warehouse::Warehouse() {}

void Warehouse::addProduct(const Product& product) {
    catalog[product.getProductId()] = product;
}

Product* Warehouse::findProduct(const std::string& id) {
    auto it = catalog.find(id);
    if (it != catalog.end()) {
        return &(it->second);
    }
    return nullptr;
}

void Warehouse::generateInventoryReport() const {
    std::cout << "\n=== Inventory Report ===" << std::endl;
    std::cout << std::left << std::setw(15) << "Product ID" 
              << std::setw(25) << "Name" 
              << std::setw(10) << "Price" 
              << std::setw(10) << "Quantity" 
              << std::setw(10) << "Available" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    for (const auto& pair : catalog) {
        const Product& product = pair.second;
        std::cout << std::left << std::setw(15) << product.getProductId()
                  << std::setw(25) << product.getName()
                  << std::setw(10) << std::fixed << std::setprecision(2) << product.getPrice()
                  << std::setw(10) << product.getQuantityInStock()
                  << std::setw(10) << (product.isAvailable() ? "Yes" : "No") << std::endl;
    }

    std::cout << std::string(70, '-') << std::endl;
}
