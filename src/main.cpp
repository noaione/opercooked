#include <stdio.h>

#include "modules/orderHistory.h"
#include "modules/beverages.h"
#include "modules/desserts.h"
#include "modules/utils.h"

// Cukup satu int main
// Jangan buat di file lain karena akan conflict.
void Main_Menu(int profit)
{
    puts("Welcome to Opercooked");
    printf("Today Profit: $ %d\n", profit);
    puts("==============================");
    puts("1. Add Dessert or Beverages");
    puts("2. View Cooking Process");
    puts("3. View Order History");
    puts("4. Order Dessert or Beverage");
    puts("5. Exit");
    printf(">> ");
}

int addNewMenu() {
    int option;
    puts("What do you want to add?");
    puts("1. Dessert");
    puts("2. Drink");
    do {
        printf("Choose: ");
        scanf("%d", &option);
        getchar();
    } while (option != 1 || option != 2);
    return option;
}

int main()
{
    int profit = 0, option, flag = 1;
    do
    {
        do
        {
            Main_Menu(profit);
            scanf("%d", &option);
            getchar();
        } while (option > 5 || option < 1);

        switch (option)
        {
        case 1:
            int pickedMenu = addNewMenu();
            if (pickedMenu == 1) {
                Dessert newdessert = addDessert();
                // add to menu list
            } else if (pickedMenu == 2) {
                Beverages newbeverage = createBeverages();
                // add to menu list
            }
            break;
        case 2:
            // Cooking_Progress();
            break;
        case 3:
            viewOrderHistory();
            break;
        case 4:
            // Order_Menu();
            break;
        case 5:
            printf("Thank You");
            flag = 0;
            return 0;
        }
    } while (flag == 1);
    return 0;
}
