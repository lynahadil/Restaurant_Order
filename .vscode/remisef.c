//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706

#include <stdio.h>
#include <string.h>
#include "restaurant.h"

void appliquerRemise(Order *head, MenuItem *menu, int id_recherche)
{
    Order *current = head;
    OrderedItem *item;
    MenuItem *dish;
    char code[20];
    char choix;
    float remise = 0.0;
    float price = 0.0;
    int nb_plats = 0;

    while (current != NULL && current->number != id_recherche)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Commande introuvable !\n");
        return;
    }

    if (current->status == COMPLETED ||
        current->status == CANCELLED)
    {
        printf("Cette commande ne peut pas etre modifiee.\n");
        return;
    }

    item = current->items;

    while (item != NULL)
    {
        dish = menu;

        while (dish != NULL && dish->id != item->itemId)
        {
            dish = dish->next;
        }

        if (dish != NULL)
        {
            price += dish->price * item->quantity;
            nb_plats += item->quantity;
        }

        item = item->next;
    }

    printf("Prix initial : %.2f DA\n", price);

    if (nb_plats >= 3)
    {
        remise += 0.10;
        printf("Remise de 10%% appliquee (3 plats ou plus) !\n");
    }

    printf("Avez-vous un code promo ? (o/n) : ");
    scanf(" %c", &choix);

    if (choix == 'o' || choix == 'O')
    {
        printf("Entrez le code promo : ");
        scanf("%19s", code);

        if (strcmp(code, "PROMO2026") == 0)
        {
            remise += 0.05;
            printf("Code promo valide ! +5%% de remise.\n");
        }
        else
        {
            printf("Code promo invalide.\n");
        }
    }

    if (remise > 0)
    {
        price = price - (price * remise);
        printf("Nouveau montant a payer : %.2f DA\n", price);
    }
    else
    {
        printf("Aucune remise appliquee. Montant a payer : %.2f DA\n", price);
    }
}
