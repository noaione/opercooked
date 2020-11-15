#include <stdio.h>

#include "modules/orderHistory.h"
#include "modules/beverages.h"
#include "modules/desserts.h"

// Cukup satu int main
// Jangan buat di file lain karena akan conflict.
void Main_Menu(int profit){
    puts("Welcome to Opercooked");
   	printf("Today Profit: $%d\n", profit);
    puts("==============================");
    puts("1. Add Dessert or Beverages");
    puts("2. View Cooking Process");
    puts("3. View Order History");
    puts("4. Order Dessert or Beverage");
    puts("5. Exit");
    printf(">> ");
}

int main(){
    int profit = 0, option, flag = 1;
    do {
        do {
            Main_Menu(profit);
            scanf("%d", &option);
	    } while(option > 5 || option < 1);

        switch (option){
        case 1:
            createBeverages();
            addDessert();
            break;
        case 2:
            // Cooking_Progress();
            break;
        case 3:
            // Order_History();
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
