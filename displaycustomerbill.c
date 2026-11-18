//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdio.h>
#include "restaurant.h"

void displayCustomerBill(Order *orders, MenuItem *menu, int orderNumber)
{
    Order *currentOrder = orders;
    OrderedItem *ordered;
    MenuItem *item;
    float subtotal, total = 0;

    /* Search for the order */
    while (currentOrder != NULL &&
           currentOrder->number != orderNumber)
    {
        currentOrder = currentOrder->next;
    }

    /* Check if the order exists */
    if (currentOrder == NULL)
    {
        printf("Order not found!\n");
        return;
    }

    ordered = currentOrder->items;

    printf("\n========== CUSTOMER BILL ==========\n");
    printf("Order Number: %d\n", currentOrder->number);
    printf("Date: %s\n", currentOrder->date);
    printf("-----------------------------------\n");

    printf("%-20s %-10s %-10s\n",
           "Item", "Quantity", "Subtotal");

    /* Display each ordered item */
    while (ordered != NULL)
    {
        item = menu;

        /* Search for the menu item */
        while (item != NULL && item->id != ordered->itemId)
        {
            item = item->next;
        }

        /* Calculate and display the subtotal */
        if (item != NULL)
        {
            subtotal = item->price * ordered->quantity;
            total += subtotal;

            printf("%-20s %-10d %.2f DA\n",
                   item->name,
                   ordered->quantity,
                   subtotal);
        }
        else
        {
            printf("Menu item with ID %d not found.\n",
                   ordered->itemId);
        }

        ordered = ordered->next;
    }

    printf("-----------------------------------\n");
    printf("TOTAL AMOUNT: %.2f DA\n", total);
    printf("===================================\n");
}
