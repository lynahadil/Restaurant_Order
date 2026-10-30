
#ifndef RESTAURANT_H
#define RESTAURANT_H

// Menu item
typedef struct MenuItem {
    int id;
    char name[50];
    char category[50];
    float price;
    struct MenuItem *next;
} MenuItem;

// Item inside an order
typedef struct OrderedItem {
    int itemId;
    int quantity;
    struct OrderedItem *next;
} OrderedItem;

// Order status
typedef enum {
    PENDING,
    PREPARING,
    COMPLETED,
    CANCELLED
} OrderStatus;

// Order
typedef struct Order {
    int number;
    char date[20];
    OrderStatus status;
    OrderedItem *items;
    struct Order *next;
} Order;

// Part 1 functions
void addMenuItem(MenuItem **head);
void deleteMenuItem(MenuItem **head, Order *orders);
void searchItem(MenuItem *head);
void displayMenu(MenuItem *head);

#endif
