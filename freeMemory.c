
//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdlib.h>
#include "restaurant.h"

void freeMemory(MenuItem *menu, Order *orders)
{
    /* Free all ordered items and orders */
    Order *currentOrder = orders;

    while (currentOrder != NULL)
    {
        OrderedItem *currentItem = currentOrder->items;

        while (currentItem != NULL)
        {
            OrderedItem *tempItem = currentItem;
            currentItem = currentItem->next;
            free(tempItem);
        }

        Order *tempOrder = currentOrder;
        currentOrder = currentOrder->next;
        free(tempOrder);
    }

    /* Free all menu items */
    MenuItem *currentMenu = menu;

    while (currentMenu != NULL)
    {
        MenuItem *tempMenu = currentMenu;
        currentMenu = currentMenu->next;
        free(tempMenu);
    }
}
