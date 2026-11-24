//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdio.h>
#include <string.h>
#include "restaurant.h"

void searchItem(MenuItem *head)
{
    MenuItem *current = head;
    int choice, id;
    char name[50];
    int found = 0;

    if (head == NULL)
    {
        printf("The menu is empty.\n");
        return;
    }

    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter item ID: ");
        scanf("%d", &id);

        while (current != NULL)
        {
            if (current->id == id)
            {
                printf("\nItem found!\n");
                printf("ID: %d\n", current->id);
                printf("Name: %s\n", current->name);
                printf("Category: %s\n", current->category);
                printf("Price: %.2f DA\n", current->price);
                found = 1;
                break;
            }

            current = current->next;
        }
    }
    else if (choice == 2)
    {
        printf("Enter item name: ");
        scanf(" %49[^\n]", name);

        while (current != NULL)
        {
            if (strcmp(current->name, name) == 0)
            {
                printf("\nItem found!\n");
                printf("ID: %d\n", current->id);
                printf("Name: %s\n", current->name);
                printf("Category: %s\n", current->category);
                printf("Price: %.2f DA\n", current->price);
                found = 1;
                break;
            }

            current = current->next;
        }
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    if (found == 0)
    {
        printf("Item not found!\n");
    }
}