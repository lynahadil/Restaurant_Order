
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"

Order *createOrder(Order *orders, MenuItem *menu)
{
    Order *H, *Q;
    OrderedItem *A, *B;
    MenuItem *P;

    int num, id, quantity, choice;
    int max = 0, found;

    // Check if the menu is empty
    if (menu == NULL)
    {
        printf("The menu is empty!\n");
        return orders;
    }

    // Find the next order number
    Q = orders;

    while (Q != NULL)
    {
        if (Q->number > max)
        {
            max = Q->number;
        }

        Q = Q->next;
    }

    num = max + 1;

    // Create a new order
    H = (Order*) malloc(sizeof(Order));

    if (H == NULL)
    {
        printf("Memory allocation error!\n");
        return orders;
    }

    H->number = num;

    printf("\nEnter order date (DD/MM/YYYY): ");
    scanf(" %19[^\n]", H->date);

    H->status = PENDING;
    H->items = NULL;
    H->next = NULL;

    // Add items to the order
    do
    {
        displayMenu(menu);

        printf("\nEnter item ID (0 to finish): ");
        scanf("%d", &id);

        if (id == 0)
        {
            break;
        }

        // Search for the selected item
        P = menu;
        found = 0;

        while (P != NULL)
        {
            if (P->id == id)
            {
                found = 1;
                break;
            }

            P = P->next;
        }

        if (found == 0)
        {
            printf("Item not found!\n");
        }
        else
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
            }
            else
            {
                // Create an ordered item
                A = (OrderedItem*) malloc(sizeof(OrderedItem));

                if (A == NULL)
                {
                    printf("Memory allocation error!\n");
                    break;
                }

                A->itemId = id;
                A->quantity = quantity;
                A->next = NULL;

                // Insert into the order items list
                if (H->items == NULL)
                {
                    H->items = A;
                }
                else
                {
                    B = H->items;

                    while (B->next != NULL)
                    {
                        B = B->next;
                    }

                    B->next = A;
                }

                printf("Item added to order!\n");
            }
        }

        printf("\nAdd another item? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    // Check if the order contains items
    if (H->items == NULL)
    {
        printf("Order cancelled: no items selected.\n");
        free(H);
        return orders;
    }

    // Insert the order into the orders list
    if (orders == NULL)
    {
        orders = H;
    }
    else
    {
        Q = orders;

        while (Q->next != NULL)
        {
            Q = Q->next;
        }

        Q->next = H;
    }

    printf("\nOrder created successfully!\n");
    printf("Order number: %d\n", H->number);

    return orders;
}
