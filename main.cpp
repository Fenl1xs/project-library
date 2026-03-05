#include <iostream>
#include <iomanip>
#include "include/Product.h"
#include "include/Warehouse.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "   ТЕСТИРОВАНИЕ СИСТЕМЫ СКЛАДА\n";
    std::cout << "========================================\n\n";

    Warehouse warehouse;

    Product p1("P001", "Ноутбук", 75000.0, 10);
    Product p2("P002", "Мышь", 1500.0, 50);
    Product p3("P003", "Клавиатура", 2500.0, 30);
    Product p4("P004", "Монитор", 18000.0, 15);

    std::cout << "📦 Добавление товаров на склад...\n";
    warehouse.addProduct(p1);
    warehouse.addProduct(p2);
    warehouse.addProduct(p3);
    warehouse.addProduct(p4);
    std::cout << "✅ Товары добавлены.\n\n";

    std::cout << "📋 НАЧАЛЬНЫЙ ОТЧЁТ:\n";
    warehouse.generateInventoryReport();
    std::cout << "\n";

    std::cout << "📈 Пополнение товара P001 (Ноутбук) на 5 шт...\n";
    Product* found = warehouse.findProduct("P001");
    if (found) {
        found->restock(5);
        std::cout << "✅ Текущее количество: " << found->getQuantityInStock() << " (ожидается 15)\n";
    } else {
        std::cout << "❌ Товар P001 не найден!\n";
    }

    std::cout << "\n💸 Продажа 2 шт товара P002 (Мышь)...\n";
    found = warehouse.findProduct("P002");
    if (found) {
        found->sell(2);
        std::cout << "✅ Текущее количество: " << found->getQuantityInStock() << " (ожидается 48)\n";
    }

    std::cout << "\n🔍 Проверка доступности товара P003 (Клавиатура)...\n";
    found = warehouse.findProduct("P003");
    if (found) {
        std::cout << "   Доступен? " << (found->isAvailable() ? "да" : "нет")
                  << " (ожидается да, т.к. 30 > 0)\n";
    }

    std::cout << "\n⚠️ Попытка продать 100 шт товара P003...\n";
    if (found) {
        found->sell(100);
        std::cout << "   Текущее количество: " << found->getQuantityInStock()
                  << " (должно остаться 30, если продажа не удалась)\n";
    }

    std::cout << "\n💰 Изменение цены товара P004 (Монитор) с 18000 на 17500...\n";
    found = warehouse.findProduct("P004");
    if (found) {
        found->setPrice(17500.0);
        std::cout << "✅ Новая цена: " << found->getPrice() << " (ожидается 17500)\n";
    }

    std::cout << "\n📋 ИТОГОВЫЙ ОТЧЁТ:\n";
    warehouse.generateInventoryReport();

    std::cout << "\n========================================\n";
    std::cout << "      ТЕСТИРОВАНИЕ ЗАВЕРШЕНО\n";
    std::cout << "========================================\n";

    return 0;
}
