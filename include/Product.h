#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string productId;
    std::string name;
    double price;
    int quantityInStock;

public:
  
    Product();
    Product(const std::string& id, const std::string& productName, 
            double productPrice, int initialQuantity);
    Product(const Product& other);
    
 
    void restock(int quantity);
    void sell(int quantity);
    bool isAvailable() const;
    
 
    std::string getProductId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantityInStock() const;
    

    void setPrice(double newPrice);
    
   
    void displayInfo() const;
};

#endif