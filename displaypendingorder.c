
#include <stdio.h>
#include "restaurant.h"

void displayPendingOrders(Order *head)
{
    Order *current = head;
    int count = 0;

    printf("PENDING ORDERS");

    if (head == NULL)
    {
        printf("No orders available.\n");
        return;
    }

    while (current != NULL)
    {
        if (current->status == PENDING ||
            current->status == PREPARING)
        {
            printf("\nOrder Number : %d\n", current->number);
            printf("Date         : %s\n", current->date);

            if (current->status == PENDING)
                printf("Status       : Pending\n");
            else
                printf("Status       : Preparing\n");

            count++;
        }

        current = current->next;
    }

    if (count == 0)
    {
        printf("There are no pending orders.\n");
    }
    else
    {
        printf("Total pending orders: %d\n", count);
    }

}
