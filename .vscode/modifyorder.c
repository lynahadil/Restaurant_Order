
#include <stdio.h>
#include "restaurant.h"

int modifyOrder(Order *head, int idOrder, int idItem, int x)
{
    Order *current = head;
    OrderedItem *item;

    while (current != NULL)
    {
        if (current->number == idOrder)
        {
            if (current->status == COMPLETED ||
                current->status == CANCELLED)
            {
                printf("This order cannot be modified.\n");
                return 0;
            }

            if (x <= 0)
            {
                printf("Invalid quantity!\n");
                return 0;
            }

            item = current->items;

            while (item != NULL)
            {
                if (item->itemId == idItem)
                {
                    item->quantity = x;
                    printf("Quantity modified successfully!\n");
                    return 1;
                }

                item = item->next;
            }

            printf("Item not found in this order.\n");
            return 0;
        }

        current = current->next;
    }

    printf("Order not found.\n");
    return 0;
}
