#include <stdio.h>
#include "restaurant.h"

void modifyOrderStatus(Order *orders, int orderNumber)
{
    Order *current = orders;
    int choice;

    while (current != NULL)
    {
        if (current->number == orderNumber)
        {
            if (current->status == CANCELLED)
            {
                printf("Cannot modify the status of a cancelled order.\n");
                return;
            }

            if (current->status == COMPLETED)
            {
                printf("This order is already completed.\n");
                return;
            }

            printf("\nCurrent status: ");

            if (current->status == PENDING)
                printf("Pending\n");
            else if (current->status == PREPARING)
                printf("Preparing\n");

            printf("\nChoose the new status:\n");

            if (current->status == PENDING)
            {
                printf("1. Preparing\n");
            }
            else if (current->status == PREPARING)
            {
                printf("1. Completed\n");
            }

            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                if (current->status == PENDING)
                {
                    current->status = PREPARING;
                    printf("Order status changed to Preparing successfully!\n");
                }
                else if (current->status == PREPARING)
                {
                    current->status = COMPLETED;
                    printf("Order status changed to Completed successfully!\n");
                }
            }
            else
            {
                printf("Invalid choice!\n");
            }

            return;
        }

        current = current->next;
    }

    printf("Order not found!\n");
}