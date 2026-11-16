float calculateTotal(Order *order, MenuItem *menu)

{

    float total = 0;

    OrderedItem *ordered = order->items;

    MenuItem *item;

    while (ordered != NULL)

    {

        item = menu;

        /* Search for the menu item */

        while (item != NULL && item->id != ordered->itemId)

        {

            item = item->next;

        }

        /* If the item exists in the menu */

        if (item != NULL)

        {

            total = total + (item->price * ordered->quantity);

        }

        ordered = ordered->next;

    }

    return total;