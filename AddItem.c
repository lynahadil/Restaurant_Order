#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"

MenuItem *addMenuItem(MenuItem *P)
{
    MenuItem *H, *Q;
    int x;
    char y[50], t[50];
    float z;

    // Enter item ID
    printf("Enter item ID: ");
    scanf("%d", &x);

    // Check if ID already exists
    Q = P;

    while (Q != NULL)
    {
        if (Q->id == x)
        {
            printf("This ID already exists!\n");
            return P;
        }

        Q = Q->next;
    }

    // Enter item name
    printf("Enter item name: ");
    scanf(" %49[^\n]", y);

    // Enter item category
    printf("Enter item category: ");
    scanf(" %49[^\n]", t);

    // Enter item price
    printf("Enter item price: ");
    scanf("%f", &z);

    if (z <= 0)
    {
        printf("Invalid price!\n");
        return P;
    }

    // Create a new node
    H = (MenuItem*) malloc(sizeof(MenuItem));

    if (H == NULL)
    {
        printf("Memory allocation error!\n");
        return P;
    }

    H->id = x;
    H->price = z;

    strcpy(H->name, y);
    strcpy(H->category, t);

    H->next = NULL;

    // Insert the node
    if (P == NULL)
    {
        P = H;
    }
    else
    {
        Q = P;

        while (Q->next != NULL)
        {
            Q = Q->next;
        }

        Q->next = H;
    }

    printf("Item added successfully!\n");

    return P;
}