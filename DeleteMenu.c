#include <stdio.h>
#include <stdlib.h>
#include "resturant.h"

MenuItem* deleteMenuItem(MenuItem *L, int DM) {
    if (L == NULL) {
        printf("The list is Empty\n");
    } else {
        if (L->id == DM) {
            MenuItem *q = L;
            L = L->next;
            free(q);
            printf("Item deleted successfully\n");
        } else {
            MenuItem *p = L;
            MenuItem *q = L->next;
            while (q != NULL && q->id != DM) {
                p = q;
                q = q->next;
            }
            if (q == NULL) {
                printf("The item doesn't exist\n");
            } else {
                p->next = q->next;
                free(q);
                printf("Item deleted successfully\n");
            }
        }
    }
    return L;
}
