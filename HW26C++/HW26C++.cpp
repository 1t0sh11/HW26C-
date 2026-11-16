#include <iostream>
#include "Order.h"

using namespace std;

int main() {
    OrdersSystem system;

    system.createOrder("16.11.2026", 14, 10, 25, "Pizza Margarita", 240.0);
    system.createOrder("16.11.2026", 14, 15, 10, "Espresso + Croissant", 95.5);
    system.createOrder("16.11.2026", 14, 5, 40, "Beef Steak", 450.0);

    cout << "Total orders created: " << Order::getTotalOrdersCount() << endl;

    system.showAll();

    cout << "\nSorting orders by ready time..." << endl;
    system.sortByReadyTime();
    system.showAll();

    system.completeFirstOrder();

    system.showAll();

    return 0;
}