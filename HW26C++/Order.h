#pragma once

#include <iostream>
#include <string>

using namespace std;

class Order {
private:
    static int totalOrdersCount;

    string orderDate;
    int orderHour;
    int orderMinute;
    int prepDuration;
    string description;
    double price;
    int orderNumber;

public:
    Order();
    Order(string date, int hour, int minute, int duration, string desc, double pr);

    static int getTotalOrdersCount();

    void setOrderDate(string date);
    string getOrderDate() const;

    void setOrderTime(int hour, int minute);
    int getOrderHour() const;
    int getOrderMinute() const;

    void setPrepDuration(int duration);
    int getPrepDuration() const;

    void setDescription(string desc);
    string getDescription() const;

    void setPrice(double pr);
    double getPrice() const;

    int getOrderNumber() const;

    int getReadyTimeInMinutes() const;
    void show() const;
};

class OrdersSystem {
private:
    Order* orders;
    int count;

public:
    OrdersSystem();
    ~OrdersSystem();

    void createOrder(string date, int hour, int minute, int duration, string desc, double price);
    void sortByReadyTime();
    void completeFirstOrder();
    void showAll() const;
};