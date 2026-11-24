
/*boudjabeur lina hadil groupe 2 matricule 242431486805
narimene sefsaf groupe 2 matricule 242431680402
boukhaoua rabah groupe 3 matricul 242431486518
moukrani bessam groupe 3 matricule 252531227706*/

#include <stdio.h>
#include "restaurant.h"

int main()
{
    MenuItem *menu = NULL;
    Order *orders = NULL;
    int choice;

    do
    {
        printf("\n\n");

        /* PROJECT TEAM */
        printf("  __________________________________________________________\n");
        printf(" |                                                          |\n");
        printf(" |                    PROJECT TEAM                          |\n");
        printf(" |__________________________________________________________|\n");
        printf(" |                                                          |\n");
        printf(" |  Boudjabeur Lina Hadil                                    |\n");
        printf(" |  Group: 2  |  Student ID: 242431486805                   |\n");
        printf(" |                                                          |\n");
        printf(" |  Narimene Sefsaf                                          |\n");
        printf(" |  Group: 2  |  Student ID: 242431680402                   |\n");
        printf(" |                                                          |\n");
        printf(" |  Boukhaoua Rabah                                          |\n");
        printf(" |  Group: 3  |  Student ID: 242431486518                   |\n");
        printf(" |                                                          |\n");
        printf(" |  Moukrani Bessam                                          |\n");
        printf(" |  Group: 3  |  Student ID: 252531227706                   |\n");
        printf(" |__________________________________________________________|\n");

        /* MAIN SCREEN */
        printf("\n");

        printf("  __________________________________________________________\n");
        printf(" |                                                          |\n");
        printf(" |              RESTAURANT ORDER MANAGER                    |\n");
        printf(" |                                                          |\n");
        printf(" |                 MANAGEMENT SYSTEM                        |\n");
        printf(" |__________________________________________________________|\n");
        printf(" |                                                          |\n");
        printf(" |                                                          |\n");

        printf(" |              __________________________                  |\n");
        printf(" |             |                          |                 |\n");
        printf(" |             |       01. KITCHEN        |                 |\n");
        printf(" |             |__________________________|                 |\n");
        printf(" |                                                          |\n");

        printf(" |              __________________________                  |\n");
        printf(" |             |                          |                 |\n");
        printf(" |             |        02. STAFF         |                 |\n");
        printf(" |             |__________________________|                 |\n");
        printf(" |                                                          |\n");

        printf(" |              __________________________                  |\n");
        printf(" |             |                          |                 |\n");
        printf(" |             |       03. CUSTOMER       |                 |\n");
        printf(" |             |__________________________|                 |\n");
        printf(" |                                                          |\n");

        printf(" |              __________________________                  |\n");
        printf(" |             |                          |                 |\n");
        printf(" |             |       04. MANAGER        |                 |\n");
        printf(" |             |__________________________|                 |\n");
        printf(" |                                                          |\n");
        printf(" |__________________________________________________________|\n");
        printf(" |                                                          |\n");
        printf(" |                 00. EXIT APPLICATION                     |\n");
        printf(" |__________________________________________________________|\n");

        printf("\n SELECT YOUR ROLE: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                kitchenMenu(orders, menu);
                break;

            case 2:
                staffMenu(&orders, menu);
                break;

            case 3:
                customerMenu(&orders, menu);
                break;

            case 4:
                managerMenu(&orders, &menu);
                break;

            case 0:
                printf("\n");
                printf("  ____________________________________________\n");
                printf(" |                                            |\n");
                printf(" |           EXITING APPLICATION              |\n");
                printf(" |____________________________________________|\n");

                freeMemory(menu, orders);

                printf("\nThank you for using Restaurant Order Manager!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 0 to 4.\n");
        }

    } while (choice != 0);

    return 0;
}
