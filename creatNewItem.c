
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"

MenuItem *creatnew(MenuItem *P, int x, char y[], char t[], float z)
{
    MenuItem *H, *Q;

    // Check ID and price
    if (x <= 0 || z <= 0)
    {
        printf("Invalid ID or price!\n");
        return P;
    }

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

    // Create a new node
    H = (MenuItem*) malloc(sizeof(MenuItem));

    if (H == NULL)
    {
        printf("Memory allocation error!\n");
        return P;
    }

    // Fill the node
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

    return P;
}
