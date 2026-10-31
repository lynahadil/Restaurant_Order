#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"

MenuItem *creatnew(MenuItem *P, int x, char y[], char t[], float z)
{
    MenuItem *H, *Q;

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