void modifyOrderStatus(Order *orders, int orderNumber)

{

    Order *current = orders;

    while (current != NULL && current->number != orderNumber)

    {

        current = current->next;

    }

    if (current == NULL)

    {

        printf("Order not found.\n");

        return;

    }

    if (current->status == Pending)

    {

        current->status = Preparing;

        printf("Order %d status changed to Preparing.\n", current->number);

    }

    else if (current->status == Preparing)

    {

        current->status = Completed;

        printf("Order %d status changed to Completed.\n", current->number);

    }

    else if (current->status == Completed)

    {

        printf("Order %d is already Completed.\n", current->number);

    }

    else if (current->status == Canceled)

    {

        printf("Order %d is Canceled and cannot be modified.\n", current->number);

    }

}