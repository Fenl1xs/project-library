#include "Product.h"
#include <iostream>


Product::Product() : productId(""), name(""), price(0.0), quantityInStock(0) {}

Product::Product(const std::string& id, const std::string& productName, 
                 double productPrice, int initialQuantity) 
    : productId(id), name(productName), price(productPrice), 
      quantityInStock(initialQuantity) {}


Product::Product(const Product& other) 
    : productId(other.productId), name(other.name), 
      price(other.price), quantityInStock(other.quantityInStock) {}

void Product::restock(int quantity) {
    if (quantity > 0) {
        quantityInStock += quantity;
        std::cout << "Товар " << name << " пополнен на " << quantity 
                 << " ед. Текущий остаток: " << quantityInStock << std::endl;
    } else {
        std::cout << "Ошибка: количество для пополнения должно быть положительным!" << std::endl;
    }
}


void Product::sell(int quantity) {
    if (quantity <= 0) {
        std::cout << "Ошибка: количество для продажи должно быть положительным!" << std::endl;
        return;
    }
    
    if (quantity <= quantityInStock) {
        quantityInStock -= quantity;
        std::cout << "Продано " << quantity << " ед. товара " << name 
                 << ". Остаток: " << quantityInStock << std::endl;
    } else {
        std::cout << "Ошибка: недостаточно товара! Доступно: " 
                 << quantityInStock << std::endl;
    }
}


bool Product::isAvailable() const {
    return quantityInStock > 0;
}


std::string Product::getProductId() const {
    return productId;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantityInStock() const {
    return quantityInStock;
}

void Product::setPrice(double newPrice) {
    if (newPrice >= 0) {
        price = newPrice;
    } else {
        std::cout << "Ошибка: цена не может быть отрицательной!" << std::endl;
    }
}


void Product::displayInfo() const {
    std::cout << "ID: " << productId 
              << ", Название: " << name 
              << ", Цена: " << price << " руб."
              << ", В наличии: " << quantityInStock 
              << (isAvailable() ? " (есть)" : " (нет)") 
              << std::endl;
}