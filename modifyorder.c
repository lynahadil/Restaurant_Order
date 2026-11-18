//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706
#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"

int modifyOrder(Order *head, MenuItem *menu, int idOrder, int idItem, int newQuantity)
{
    Order *currentOrder = head;
    MenuItem *menuItem = NULL;
    OrderedItem *currentItem;
    OrderedItem *previousItem = NULL;

    /* 1. Search for the order */
    while (currentOrder != NULL && currentOrder->number != idOrder)
    {
        currentOrder = currentOrder->next;
    }

    if (currentOrder == NULL)
    {
        printf("Order not found.\n");
        return 0;
    }

    /* 2. Check order status */
    if (currentOrder->status == COMPLETED ||
        currentOrder->status == CANCELLED)
    {
        printf("This order cannot be modified.\n");
        return 0;
    }

    /* 3. Check quantity */
    if (newQuantity < 0)
    {
        printf("Invalid quantity.\n");
        return 0;
    }

    /* 4. Search for the item in the menu */
    menuItem = menu;

    while (menuItem != NULL && menuItem->id != idItem)
    {
        menuItem = menuItem->next;
    }

    if (menuItem == NULL)
    {
        printf("Item not found in menu.\n");
        return 0;
    }

    /* 5. Search for the item in the order */
    currentItem = currentOrder->items;

    while (currentItem != NULL && currentItem->itemId != idItem)
    {
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    /* 6. If the item already exists in the order */
    if (currentItem != NULL)
    {
        /* Quantity = 0 means remove the item */
        if (newQuantity == 0)
        {
            if (previousItem == NULL)
            {
                currentOrder->items = currentItem->next;
            }
            else
            {
                previousItem->next = currentItem->next;
            }

            free(currentItem);

            printf("Item removed from order successfully.\n");
            return 1;
        }

        /* Otherwise, update the quantity */
        currentItem->quantity = newQuantity;

        printf("Item quantity updated successfully.\n");
        return 1;
    }

    /* 7. If the item does not exist in the order */
    if (newQuantity == 0)
    {
        printf("This item is not present in the order.\n");
        return 0;
    }

    /* 8. Create a new OrderedItem node */
    OrderedItem *newItem = malloc(sizeof(OrderedItem));

    if (newItem == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    newItem->itemId = idItem;
    newItem->quantity = newQuantity;
    newItem->next = NULL;

    /* 9. Insert the new item at the end of the order */
    if (currentOrder->items == NULL)
    {
        currentOrder->items = newItem;
    }
    else
    {
        OrderedItem *lastItem = currentOrder->items;

        while (lastItem->next != NULL)
        {
            lastItem = lastItem->next;
        }

        lastItem->next = newItem;
    }

    printf("New item added to order successfully.\n");

    return 1;
}