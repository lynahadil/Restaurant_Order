
//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706


#include <stdio.h>
#include "restaurant.h"

/* Search for an order by its number */
static Order *findOrderInRoleMenus(Order *orders, int orderNumber)
{
    Order *current = orders;

    while (current != NULL)
    {
        if (current->number == orderNumber)
            return current;

        current = current->next;
    }

    return NULL;
}

/* Display menu header */
void displayPanelTitle(const char *title)
{
    printf("\n");
    printf(" ____________________________________________\n");
    printf("|                                            |\n");
    printf("|              %-26s      |\n", title);
    printf("|____________________________________________|\n");
}

/* KITCHEN PANEL */
void kitchenMenu(Order *orders, MenuItem *menu)
{
    int choice;
    int orderNumber;

    do
    {
        displayPanelTitle("KITCHEN PANEL");

        printf("|                                            |\n");
        printf("|  1. Display Pending Orders                 |\n");
        printf("|  2. Update Order Status                    |\n");
        printf("|                                            |\n");
        printf("|  0. Return to Main Menu                    |\n");
        printf("|____________________________________________|\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayPendingOrders(orders, menu);
                break;

            case 2:
                printf("Enter order number: ");
                scanf("%d", &orderNumber);
                modifyOrderStatus(orders, orderNumber);
                break;

            case 0:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}

/* STAFF PANEL */
void staffMenu(Order **orders, MenuItem *menu)
{
    int choice;
    int orderNumber;
    int itemId;
    int quantity;

    Order *selectedOrder;

    do
    {
        displayPanelTitle("STAFF PANEL");

        printf("|                                            |\n");
        printf("|  1. Display Restaurant Menu                |\n");
        printf("|  2. Create New Order                       |\n");
        printf("|  3. Modify Order                           |\n");
        printf("|  4. Cancel Order                           |\n");
        printf("|  5. Display Customer Bill                  |\n");
        printf("|  6. Calculate Order Total                  |\n");
        printf("|  7. Display Pending Orders                 |\n");
        printf("|                                            |\n");
        printf("|  0. Return to Main Menu                    |\n");
        printf("|____________________________________________|\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayMenu(menu);
                break;

            case 2:
                *orders = createOrder(*orders, menu);
                break;

            case 3:
                printf("Enter order number: ");
                scanf("%d", &orderNumber);

                printf("Enter menu item ID: ");
                scanf("%d", &itemId);

                printf("Enter new quantity (0 to remove): ");
                scanf("%d", &quantity);

                modifyOrder(*orders, menu, orderNumber,
                            itemId, quantity);
                break;

            case 4:
                printf("Enter order number to cancel: ");
                scanf("%d", &orderNumber);
                cancelOrder(*orders, orderNumber);
                break;

            case 5:
                printf("Enter order number: ");
                scanf("%d", &orderNumber);
                displayCustomerBill(*orders, menu, orderNumber);
                break;

            case 6:
                printf("Enter order number: ");
                scanf("%d", &orderNumber);

                selectedOrder =
                    findOrderInRoleMenus(*orders, orderNumber);

                if (selectedOrder != NULL)
                {
                    printf("Order Total: %.2f DA\n",
                           calculateTotal(selectedOrder, menu));
                }
                else
                {
                    printf("Order not found.\n");
                }
                break;

            case 7:
                displayPendingOrders(*orders, menu);
                break;

            case 0:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}

/* CUSTOMER PANEL */
void customerMenu(Order **orders, MenuItem *menu)
{
    int choice;
    int orderNumber;

    do
    {
        displayPanelTitle("CUSTOMER PANEL");

        printf("|                                            |\n");
        printf("|  1. View Restaurant Menu                   |\n");
        printf("|  2. Place an Order                         |\n");
        printf("|  3. View Order Bill                        |\n");
        printf("|                                            |\n");
        printf("|  0. Return to Main Menu                    |\n");
        printf("|____________________________________________|\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayMenu(menu);
                break;

            case 2:
                *orders = createOrder(*orders, menu);
                break;

            case 3:
                printf("Enter your order number: ");
                scanf("%d", &orderNumber);
                displayCustomerBill(*orders, menu, orderNumber);
                break;

            case 0:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}

/* MANAGER PANEL */
void managerMenu(Order **orders, MenuItem **menu)
{
    int choice;
    int itemId;
    int orderNumber;

    Order *selectedOrder;

    do
    {
        displayPanelTitle("MANAGER PANEL");

        printf("|                                            |\n");
        printf("|  1. Add Menu Item                          |\n");
        printf("|  2. Delete Menu Item                       |\n");
        printf("|  3. Search Menu Item                       |\n");
        printf("|  4. Display Restaurant Menu                |\n");
        printf("|  5. Display Statistics                     |\n");
        printf("|  6. Apply Discount                         |\n");
        printf("|  7. Save Order to History                  |\n");
        printf("|  8. Display Pending Orders                 |\n");
        printf("|                                            |\n");
        printf("|  0. Return to Main Menu                    |\n");
        printf("|____________________________________________|\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                *menu = addMenuItem(*menu);
                break;

            case 2:
                printf("Enter menu item ID to delete: ");
                scanf("%d", &itemId);
                *menu = deleteMenuItem(*menu, itemId, *orders);
                break;

            case 3:
                searchItem(*menu);
                break;

            case 4:
                displayMenu(*menu);
                break;

            case 5:
                affichestatic(*orders, *menu);
                break;

            case 6:
                printf("Enter order number for discount: ");
                scanf("%d", &orderNumber);
                appliquerRemise(*orders, *menu, orderNumber);
                break;

            case 7:
                printf("Enter order number to save: ");
                scanf("%d", &orderNumber);

                selectedOrder =
                    findOrderInRoleMenus(*orders, orderNumber);

                if (selectedOrder != NULL)
                {
                    saveOrderToFile(selectedOrder, *menu);
                    printf("Order saved to history.\n");
                }
                else
                {
                    printf("Order not found.\n");
                }
                break;

            case 8:
                displayPendingOrders(*orders, *menu);
                break;

            case 0:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}
