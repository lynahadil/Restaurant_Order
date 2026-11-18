//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdio.h>
#include "restaurant.h"


float calculateTotal(Order *order, MenuItem *menu)
{
    float total = 0;

    if (order == NULL)
    {
        return 0;
    }

    OrderedItem *ordered = order->items;
    MenuItem *item;

    while (ordered != NULL)
    {
        item = menu;

        /* Search for the menu item */
        while (item != NULL && item->id != ordered->itemId)
        {
            item = item->next;
        }

        /* Calculate the subtotal if the item exists */
        if (item != NULL)
        {
            total = total + (item->price * ordered->quantity);
        }

        ordered = ordered->next;
    }

    return total;
}
