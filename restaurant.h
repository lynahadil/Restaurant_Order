//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
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
void displayMenu(MenuItem *menu);
float calculateTotal(Order *order, MenuItem *menu);

// Order functions
Order *createOrder(Order *orders, MenuItem *menu);
int modifyOrder(Order *head, MenuItem *menu, int idOrder, int idItem, int newQuantity);
void cancelOrder(Order *head, int orderNumber);
void displayPendingOrders(Order *head, MenuItem *menu);
void affichestatic(Order *head, MenuItem *menu);
void appliquerRemise(Order *head, MenuItem *menu, int id_recherche);
void displayCustomerBill(Order *orders, MenuItem *menu, int orderNumber);
void saveOrderToFile(Order *order, MenuItem *menu);
void modifyOrderStatus(Order *orders, int orderNumber);
void freeMemory(MenuItem *menu, Order *orders);


// Role functions
void kitchenMenu(Order *orders, MenuItem *menu);
void staffMenu(Order **orders, MenuItem *menu);
void customerMenu(Order **orders, MenuItem *menu);
void managerMenu(Order **orders, MenuItem **menu);

#endif
