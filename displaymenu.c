
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
