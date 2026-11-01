
#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"

MenuItem *deleteMenuItem(MenuItem *L, int DM, Order *orders)
{
    MenuItem *p, *q;
    Order *current;
    OrderedItem *item;

    // Check if the menu is empty
    if (L == NULL)
    {
        printf("The list is empty!\n");
        return L;
    }

    // Check if the item is used in an active order
    current = orders;

    while (current != NULL)
    {
        if (current->status == PENDING ||
            current->status == PREPARING)
        {
            item = current->items;

            while (item != NULL)
            {
                if (item->itemId == DM)
                {
                    printf("Cannot delete this item. It is used in an active order.\n");
                    return L;
                }

                item = item->next;
            }
        }

        current = current->next;
    }

    // Delete the first node
    if (L->id == DM)
    {
        q = L;
        L = L->next;
        free(q);

        printf("Item deleted successfully!\n");
    }
    else
    {
        p = L;
        q = L->next;

        while (q != NULL && q->id != DM)
        {
            p = q;
            q = q->next;
        }

        if (q == NULL)
        {
            printf("The item doesn't exist!\n");
        }
        else
        {
            p->next = q->next;
            free(q);

            printf("Item deleted successfully!\n");
        }
    }

    return L;
}
