//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706

#include <stdio.h>
#include "restaurant.h"

void displayPendingOrders(Order *head, MenuItem *menu)
{
    Order *current = head;
    OrderedItem *ordered;
    MenuItem *item;
    int count = 0;

    printf("\n");
    printf("________________________________________________\n");
    printf("|              PENDING ORDERS                  |\n");
    printf("|______________________________________________|\n");

    if (head == NULL)
    {
        printf("|          NO ORDERS AVAILABLE                 |\n");
        printf("|______________________________________________|\n");
        return;
    }

    while (current != NULL)
    {
        if (current->status == PENDING ||
            current->status == PREPARING)
        {
            count++;

            printf("\n");
            printf("| ORDER NUMBER: %-32d|\n", current->number);
            printf("| DATE: %-41s|\n", current->date);

            if (current->status == PENDING)
                printf("| STATUS: PENDING                               |\n");
            else
                printf("| STATUS: PREPARING                             |\n");

            printf("|----------------------------------------------|\n");
            printf("| ITEMS TO PREPARE:                            |\n");

            ordered = current->items;

            while (ordered != NULL)
            {
                item = menu;

                /* Find the item name using its ID */
                while (item != NULL &&
                       item->id != ordered->itemId)
                {
                    item = item->next;
                }

                if (item != NULL)
                {
                    printf("| %-28s Quantity: %-3d|\n",
                           item->name,
                           ordered->quantity);
                }
                else
                {
                    printf("| Item ID: %-19d Quantity: %-3d|\n",
                           ordered->itemId,
                           ordered->quantity);
                }

                ordered = ordered->next;
            }

            printf("|______________________________________________|\n");
        }

        current = current->next;
    }

    if (count == 0)
    {
        printf("\n|          NO PENDING ORDERS                   |\n");
        printf("|______________________________________________|\n");
    }
    else
    {
        printf("\n  TOTAL ACTIVE ORDERS: %d\n", count);
    }
}
