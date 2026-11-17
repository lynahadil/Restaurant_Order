//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdio.h>
#include "restaurant.h"

void displayMenu(MenuItem *menu)
{
    MenuItem *current = menu;

    if (current == NULL)
    {
        printf("The menu is empty.\n");
        return;
    }

    printf("\n========== RESTAURANT MENU ==========\n");

    while (current != NULL)
    {
        printf("ID       : %d\n", current->id);
        printf("Name     : %s\n", current->name);
        printf("Category : %s\n", current->category);
        printf("Price    : %.2f\n", current->price);
        printf("-------------------------------------\n");

        current = current->next;
    }
}
float calculateTotal(Order *order, MenuItem *menu)

{

    float total = 0;

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

        /* If the item exists in the menu */

        if (item != NULL)

        {

            total = total + (item->price * ordered->quantity);

        }

        ordered = ordered->next;

    }

    return total;
