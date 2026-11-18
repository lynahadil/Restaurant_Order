//boudjabeur lina hadil groupe 2 matricule 242431486805
//narimene sefsaf groupe 2 matricule 242431680402
//boukhaoua rabah groupe 3 matricul 242431486518
//moukrani bessam groupe 3 matricul 252531227706

#include <stdio.h>
#include "restaurant.h"

/* Search for an order by its number */
Order *findOrder(Order *orders, int orderNumber)
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

int main()
{
    MenuItem *menu = NULL;
    Order *orders = NULL;

    int choice;
    int id;
    int orderNumber;
    int itemId;
    int quantity;

    /* Display project team */
    printf("\n============================================\n");
    printf("                 PROJECT TEAM               \n");
    printf("============================================\n");

    printf("1. Boudjabeur Lina Hadil\n");
    printf("   Group: 2 | Student ID: 242431486805\n\n");

    printf("2. Narimene Sefsaf\n");
    printf("   Group: 2 | Student ID: 242431680402\n\n");

    printf("3. Boukhaoua Rabah\n");
    printf("   Group: 3 | Student ID: 242431486518\n\n");

    printf("4. Moukrani Bessam\n");
    printf("   Group: 3 | Student ID: 252531227706\n");

    printf("============================================\n");

    printf("\n========================================\n");
    printf("       RESTAURANT ORDER MANAGEMENT      \n");
    printf("========================================\n");

    do
    {
        printf("\n");
        printf("------------- MAIN MENU -------------\n");
        printf("1.  Add Menu Item\n");
        printf("2.  Delete Menu Item\n");
        printf("3.  Search Menu Item\n");
        printf("4.  Display Menu\n");
        printf("5.  Create Order\n");
        printf("6.  Modify Order\n");
        printf("7.  Cancel Order\n");
        printf("8.  Calculate Order Total\n");
        printf("9.  Display Pending Orders\n");
        printf("10. Modify Order Status\n");
        printf("11. Display Statistics\n");
        printf("12. Display Customer Bill\n");
        printf("13. Save Order to History\n");
        printf("14. Apply Discount\n");
        printf("0.  Exit Application\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                menu = addMenuItem(menu);
                break;

            case 2:
                printf("Enter menu item ID to delete: ");
                scanf("%d", &id);

                menu = deleteMenuItem(menu, id, orders);
                break;

            case 3:
                searchItem(menu);
                break;

            case 4:
                displayMenu(menu);
                break;

            case 5:
                orders = createOrder(orders, menu);
                break;

            case 6:
                printf("Enter order number: ");
                scanf("%d", &orderNumber);

                printf("Enter menu item ID: ");
                scanf("%d", &itemId);

                printf("Enter new quantity (0 to remove): ");
                scanf("%d", &quantity);

                modifyOrder(orders, menu, orderNumber, itemId, quantity);
                break;

            case 7:
                printf("Enter order number to cancel: ");
                scanf("%d", &orderNumber);

                cancelOrder(orders, orderNumber);
                break;

            case 8:
            {
                printf("Enter order number: ");
                scanf("%d", &orderNumber);

                Order *selectedOrder = findOrder(orders, orderNumber);

                if (selectedOrder != NULL)
                {
                    printf("Order total: %.2f DA\n",
                           calculateTotal(selectedOrder, menu));
                }
                else
                {
                    printf("Order not found.\n");
                }

                break;
            }

            case 9:
                displayPendingOrders(orders);
                break;

            case 10:
                printf("Enter order number: ");
                scanf("%d", &orderNumber);

                modifyOrderStatus(orders, orderNumber);
                break;

            case 11:
                affichestatic(orders, menu);
                break;

            case 12:
                printf("Enter order number: ");
                scanf("%d", &orderNumber);

                displayCustomerBill(orders, menu, orderNumber);
                break;

            case 13:
            {
                printf("Enter order number to save: ");
                scanf("%d", &orderNumber);

                Order *selectedOrder = findOrder(orders, orderNumber);

                if (selectedOrder != NULL)
                {
                    saveOrderToFile(selectedOrder, menu);
                    printf("Order saved to history.\n");
                }
                else
                {
                    printf("Order not found.\n");
                }

                break;
            }

            case 14:
                printf("Enter order number for discount: ");
                scanf("%d", &orderNumber);

                appliquerRemise(orders, menu, orderNumber);
                break;

            case 0:
                printf("\nExiting application...\n");

                freeMemory(menu, orders);

                printf("Memory freed successfully.\n");
                printf("Thank you for using Restaurant Order Management!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
