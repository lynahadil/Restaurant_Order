//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"

void cancelOrder(Order *head, int orderNumber)
{
    Order *current = head;

    while (current != NULL)
    {
        if (current->number == orderNumber)
        {
            if (current->status == COMPLETED)
            {
                printf("Cannot cancel this order. It is already completed.\n");
                return;
            }

            if (current->status == CANCELLED)
            {
                printf("This order is already cancelled.\n");
                return;
            }

            current->status = CANCELLED;

            printf("Order %d has been cancelled successfully.\n",
                   orderNumber);
            return;
        }

        current = current->next;
    }

    printf("Order not found.\n");
}
