#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"


void saveOrderToFile(Order *order, MenuItem *menu)
{
    FILE *file = fopen("orders_history.txt", "a");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    float total = 0;
    OrderedItem *current = order->items;

    while (current != NULL)
    {
        MenuItem *item = menu;

        while (item != NULL)
        {
            if (item->id == current->itemId)
            {
                total += item->price * current->quantity;
                break;
            }

            item = item->next;
        }

        current = current->next;
    }

    fprintf(file, "Order: %d | Date: %s | Total: %.2f DA\n",
            order->number, order->date, total);

    fclose(file);
}
