#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <map>
#include "Product.h"

class Warehouse {
public:
    Warehouse();

    void addProduct(const Product& product);
    Product* findProduct(const std::string& id);
    void generateInventoryReport() const;

private:
    std::map<std::string, Product> catalog;
};

#endif // WAREHOUSE_H
