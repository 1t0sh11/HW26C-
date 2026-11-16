#include "Order.h"

int Order::totalOrdersCount = 0;

Order::Order() {
    orderDate = "01.01.2026";
    orderHour = 0;
    orderMinute = 0;
    prepDuration = 0;
    description = "None";
    price = 0.0;
    orderNumber = 0;
}

Order::Order(string date, int hour, int minute, int duration, string desc, double pr) {
    totalOrdersCount++;
    orderDate = date;
    orderHour = hour;
    orderMinute = minute;
    prepDuration = duration;
    description = desc;
    price = pr;
    orderNumber = totalOrdersCount;
}

int Order::getTotalOrdersCount() {
    return totalOrdersCount;
}

void Order::setOrderDate(string date) { orderDate = date; }
string Order::getOrderDate() const { return orderDate; }

void Order::setOrderTime(int hour, int minute) {
    orderHour = hour;
    orderMinute = minute;
}
int Order::getOrderHour() const { return orderHour; }
int Order::getOrderMinute() const { return orderMinute; }

void Order::setPrepDuration(int duration) { prepDuration = duration; }
int Order::getPrepDuration() const { return prepDuration; }

void Order::setDescription(string desc) { description = desc; }
string Order::getDescription() const { return description; }

void Order::setPrice(double pr) { price = pr; }
double Order::getPrice() const { return price; }

int Order::getOrderNumber() const { return orderNumber; }

int Order::getReadyTimeInMinutes() const {
    return orderHour * 60 + orderMinute + prepDuration;
}

void Order::show() const {
    int readyTotal = getReadyTimeInMinutes();
    int readyH = (readyTotal / 60) % 24;
    int readyM = readyTotal % 60;

    cout << "Order #" << orderNumber << " | Date: " << orderDate << endl;
    cout << "  Description: " << description << " | Price: " << price << " UAH" << endl;

    cout << "  Order time: ";
    if (orderHour < 10) cout << "0";
    cout << orderHour << ":";
    if (orderMinute < 10) cout << "0";
    cout << orderMinute;

    cout << " | Prep duration: " << prepDuration << " min | Ready at: ";
    if (readyH < 10) cout << "0";
    cout << readyH << ":";
    if (readyM < 10) cout << "0";
    cout << readyM << endl;
    cout << "--------------------------------------------------" << endl;
}

OrdersSystem::OrdersSystem() {
    orders = nullptr;
    count = 0;
}

OrdersSystem::~OrdersSystem() {
    if (orders != nullptr) {
        delete[] orders;
    }
}

void OrdersSystem::createOrder(string date, int hour, int minute, int duration, string desc, double price) {
    Order newOrder(date, hour, minute, duration, desc, price);

    Order* temp = new Order[count + 1];
    for (int i = 0; i < count; i++) {
        temp[i] = orders[i];
    }
    temp[count] = newOrder;

    if (orders != nullptr) {
        delete[] orders;
    }
    orders = temp;
    count++;
}

void OrdersSystem::sortByReadyTime() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (orders[j].getReadyTimeInMinutes() > orders[j + 1].getReadyTimeInMinutes()) {
                Order temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }
}

void OrdersSystem::completeFirstOrder() {
    if (count == 0) {
        cout << "No active orders to complete!" << endl;
        return;
    }

    cout << "\n=== COMPLETING FIRST ORDER ===" << endl;
    orders[0].show();

    if (count == 1) {
        delete[] orders;
        orders = nullptr;
        count = 0;
    }
    else {
        Order* temp = new Order[count - 1];
        for (int i = 1; i < count; i++) {
            temp[i - 1] = orders[i];
        }
        delete[] orders;
        orders = temp;
        count--;
    }
}

void OrdersSystem::showAll() const {
    if (count == 0) {
        cout << "The order queue is empty." << endl;
        return;
    }

    cout << "\n=== CURRENT ORDERS LIST (" << count << ") ===" << endl;
    for (int i = 0; i < count; i++) {
        orders[i].show();
    }
}