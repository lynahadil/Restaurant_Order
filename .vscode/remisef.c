#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct order {
    int id;             // Numéro de la commande (utile pour la rechercher)
    float price;
    int nb_plats;       // Nombre total de plats commandés dans cette commande
    int status;         // 0 = en attente, 1 = terminée
    struct order *next;
} order;

// Fonction pour appliquer la remise (3 plats ou plus) + code promo
void appliquerRemise(order* head, int id_recherche) {
    order *current = head;
    char code[20];
    char choix;
    float remise = 0.0;

    // 1. Rechercher la commande dans la liste chaînée
    while (current != NULL && current->id != id_recherche) {
        current = current->next;
    }

    // Si la commande n'existe pas
    if (current == NULL) {
        printf("Commande introuvable !\n");
        return;
    }

    printf("Prix initial : %.2f DA\n", current->price);

    // 2. Vérifier si le client a commandé 3 plats ou plus
    if (current->nb_plats >= 3) {
        remise += 0.10; // 10% de remise
        printf("Remise de 10%% appliquee (3 plats ou plus) !\n");
    }

    // 3. Vérifier si le client a un code promo
    printf("Avez-vous un code promo ? (o/n) : ");
    scanf(" %c", &choix);

    if (choix == 'o' || choix == 'O') {
        printf("Entrez le code promo : ");
        scanf("%s", code);

        if (strcmp(code, "PROMO2026") == 0) {
            remise += 0.05; // 5% supplémentaire
            printf("Code promo valide ! +5%% de remise.\n");
        } else {
            printf("Code promo invalide.\n");
        }
    }

    // 4. Mettre à jour le prix final de la commande
    if (remise > 0) {
        current->price = current->price - (current->price * remise);
        printf("Nouveau montant a payer : %.2f DA\n", current->price);
    } else {
        printf("Aucune remise appliquee. Montant a payer : %.2f DA\n", current->price);
    }
}