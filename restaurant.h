
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

// Menu functions
MenuItem *addMenuItem(MenuItem *P);
MenuItem *creatnew(MenuItem *P, int x, char y[], char t[], float z);
MenuItem *deleteMenuItem(MenuItem *L, int DM, Order *orders);
void searchItem(MenuItem *head);
void displayMenu(MenuItem *head);

// Order functions
Order *createOrder(Order *orders, MenuItem *menu);
void cancelOrder(Order *head, int orderNumber);
#endif
