void displayCustomerBill(Order *orders, MenuItem *menu, int orderNumber)

{

    Order *currentOrder = orders;

    OrderedItem *ordered;

    MenuItem *item;

    float subtotal, total = 0;

    /* Search for the order */

    while (currentOrder != NULL &&

           currentOrder->number != orderNumber)

    {

        currentOrder = currentOrder->next;

    }

    if (currentOrder == NULL)

    {

        printf("Order not found!\n");

        return;

    }

    ordered = currentOrder->items;

    printf("\n========== CUSTOMER BILL ==========\n");

    printf("Order Number: %d\n", currentOrder->number);

    printf("Date: %s\n", currentOrder->date);

    printf(" ————————————\n");

    printf("%-15s %-8s %-10s\n",

           "Item", "Quantity", "Subtotal");

    while (ordered != NULL)

    {

        item = menu;

        /* Search for the menu item */

        while (item != NULL && item->id != ordered->itemId)

        {

            item = item->next;

        }

        if (item != NULL)

        {

            subtotal = item->price * ordered->quantity;

            total += subtotal;

            printf("%-15s %-8d %.2f DA\n",

                   item->name,

                   ordered->quantity,

                   subtotal);

        }

        ordered = ordered->next;

    }

    printf(" ————————————\n");

    printf("TOTAL AMOUNT: %.2f DA\n", total);

    printf("===================================\n");

}