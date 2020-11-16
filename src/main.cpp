#include <stdio.h>

#include "modules/orderHistory.h"
#include "modules/beverages.h"
#include "modules/desserts.h"
#include "modules/utils.h"
#include "modules/cookingProcess.h"

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
    // printf(">> ");
}

int addNewMenu() {
    int menupicked = 0;
    puts("What do you want to add?");
    puts("1. Dessert");
    puts("2. Drink");
    while (menupicked < 1 || menupicked > 2) {
        printf("Choose: ");
        scanf("%d", &menupicked);
        getchar();
    }
    return menupicked;
}

int main()
{
    int profit = 0, option = 0, flag = 1;
    while (flag) {
        Main_Menu(profit);
        while (option < 1 || option > 5) {
            printf(">> ");
            scanf("%d", &option);
            getchar();
        }

        switch (option) {
            case 1:
                {
                    puts("");
                    int pickedMenu = addNewMenu();
                    puts("");
                    if (pickedMenu == 1) {
                        Dessert newdessert = addDessert();
                        // add to menu list
                    } else if (pickedMenu == 2) {
                        Beverages newbeverage = createBeverages();
                        // add to menu list
                    }
                    break;
                }
            case 2:
                {
                    puts("");
                    cookedData cookProcess = viewCookProcess();
                    if (cookProcess.totalCooked + 1 > 0) {
                        for (int i = 0; i < cookProcess.totalCooked + 1; i++) {
                            if (cookProcess.cookedItems[i].type == 0) {
                                // dessert
                                putHistoryDesserts(cookProcess.cookedItems[i].desserts);
                                profit += cookProcess.cookedItems[i].price;
                            } else if (cookProcess.cookedItems[i].type == 1) {
                                // beverages
                                putHistoryBeverages(cookProcess.cookedItems[i].drinks);
                                profit += cookProcess.cookedItems[i].price;
                            }
                        }
                    }
                    break;
                }
            case 3:
                puts("");
                viewOrderHistory();
                break;
            case 4:
                puts("");
                // Order_Menu();
                // if dessert, cookDessert(xxxxxx);
                // if beverages, cookBeverage(xxxxxx);
                break;
            case 5:
                puts("Thank You");
                flag = 0;
                return 0;
        }
        // reset option
        option = 0;
    }
    return 0;
}
