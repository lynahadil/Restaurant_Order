//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706

#include <stdio.h>
#include <string.h>
#include "restaurant.h"

// Function to apply discounts to an order
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

    // 1. Search for the order in the linked list
    while (current != NULL && current->number != id_recherche)
    {
        current = current->next;
    }

    // Check if the order exists
    if (current == NULL)
    {
        printf("Order not found!\n");
        return;
    }

    // Check if the order can be modified
    if (current->status == COMPLETED ||
        current->status == CANCELLED)
    {
        printf("This order cannot be modified.\n");
        return;
    }

    // 2. Calculate the initial price and total number of dishes
    item = current->items;

    while (item != NULL)
    {
        dish = menu;

        // Search for the dish in the menu
        while (dish != NULL && dish->id != item->itemId)
        {
            dish = dish->next;
        }

        // Calculate the price and quantity
        if (dish != NULL)
        {
            price += dish->price * item->quantity;
            nb_plats += item->quantity;
        }

        item = item->next;
    }

    printf("Initial price: %.2f DA\n", price);

    // 3. Apply a 10% discount if the order contains at least 3 dishes
    if (nb_plats >= 3)
    {
        remise += 0.10;
        printf("10%% discount applied (3 dishes or more)!\n");
    }

    // 4. Ask the customer if they have a promotional code
    printf("Do you have a promo code? (y/n): ");
    scanf(" %c", &choix);

    if (choix == 'y' || choix == 'Y')
    {
        printf("Enter the promo code: ");
        scanf("%19s", code);

        // Check if the promotional code is valid
        if (strcmp(code, "PROMO2026") == 0)
        {
            remise += 0.05;
            printf("Valid promo code! Additional 5%% discount.\n");
        }
        else
        {
            printf("Invalid promo code.\n");
        }
    }

    // 5. Calculate and display the final price
    if (remise > 0)
    {
        price = price - (price * remise);
        printf("New amount to pay: %.2f DA\n", price);
    }
    else
    {
        printf("No discount applied. Amount to pay: %.2f DA\n", price);
    }
}
