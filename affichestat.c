//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdio.h>
#include "restaurant.h"

void affichestatic(Order *head, MenuItem *menu)
{
    int cpt_t = 0;
    int cpt_attente = 0;
    float pricef = 0.0;
    Order *current = head;

    while (current != NULL)
    {
        cpt_t++;

        if (current->status == COMPLETED)
        {
            pricef += calculateOrderTotal(current, menu);
        }
        else if (current->status == PENDING ||
                 current->status == PREPARING)
        {
            cpt_attente++;
        }

        current = current->next;
    }

    printf("nombre total de command :%d\n", cpt_t);
    printf("nombre de command en attente : %d\n", cpt_attente);
    printf("Montant totaldes command teminees:%.2f\n", pricef);
}