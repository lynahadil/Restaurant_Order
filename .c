
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"

void addMenuItem(MenuItem **head)
{
    int id;
    float price;

    
    printf("Enter item ID: ");
    scanf("%d", &id);

    MenuItem *temp = *head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("Error: This ID already exists!\n");
            return;
        }

        temp = temp->next;
    }

   
    MenuItem *newItem = malloc(sizeof(MenuItem));

    if (newItem == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newItem->id = id;

    
    printf("Enter item name: ");
    scanf(" %49[^\n]", newItem->name);

    
    printf("Enter category: ");
    scanf(" %49[^\n]", newItem->category);

    
    printf("Enter unit price: ");
    scanf("%f", &price);

    if (price <= 0)
    {
        printf("Invalid price!\n");
        free(newItem);
        return;
    }

    newItem->price = price;

    
    newItem->next = NULL;

    if (*head == NULL)
    {
        *head = newItem;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newItem;
    }

    printf("\nMenu item added successfully!\n");
}
