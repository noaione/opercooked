#include <stdio.h>
#include "order.h"
#include "beverages.h"
#include "desserts.h"

// Maximum 100
MenuOpercooked ListOrderMenu[100];
int ctrMenu = -1;

void addBeveragesToList(Beverages menuBaru) 
{
    ctrMenu++;
    ListOrderMenu[ctrMenu].beverageData = menuBaru;
    ListOrderMenu[ctrMenu].type = 'b'; // b for beverages
}

void addDessertToList(Dessert menuBaru) 
{
    ctrMenu++;
    ListOrderMenu[ctrMenu].dessertData = menuBaru;
    ListOrderMenu[ctrMenu].type = 'd'; // d for dessert
}

// Panggil function ini dari main.cpp
// #include "modules/order.h"

// MenuOpercooked orderBaru = newOrder();
// if (orderBaru.type == 'e') {
//     // ignore since it's empty data
// } else if (orderBaru.type == 'd') {
//     // dessert
//     addToDessertCookingList(orderBaru.dessertData);
// } else if (orderBaru.type == 'b') {
//     // beverage
//     addToBeveragesCookingList(orderBaru.dessertData);
// }

MenuOpercooked newOrder() 
{
    if (ctrMenu == -1) 
    {
        printf("There is no Dessert or Drink on the List!\n\n");
        printf("Press Enter to continue");
        getchar();
        MenuOpercooked emptyPlaceholder;
        emptyPlaceholder.type = 'e'; // e for empty data. (as in placeholder)
        return emptyPlaceholder;
    } 
    else 
    {
        // generate table
        int i = 0;
        printf("| No\t| Name\t\t\t| Price\t| Topping\t\t| Callories\t| Flavor\t\t| Size\t|\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
        while (i <= ctrMenu) 
        {   //Beverages
            if (ListOrderMenu[i].type == 'b') 
            {
                printf("| %d\t| %s\t\t\t| %d\t| -\t\t| -\t| %s\t\t| %s\t|\n", i + 1, ListOrderMenu[i].beverageData.name, ListOrderMenu[i].beverageData.price, ListOrderMenu[i].beverageData.flavor, ListOrderMenu[i].beverageData.size);
            }
            //Desserts
            else 
            {
                printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| %.2f\t| -\t\t| -\t|\n", i + 1, ListOrderMenu[i].dessertData.Dessert_Name, ListOrderMenu[i].dessertData.Price, ListOrderMenu[i].dessertData.Topping, ListOrderMenu[i].dessertData.callories);
            }
            i++;
        }
        int pickedData = 0;
        do 
        {
            printf("Choose a menu to order [1 - %d]: ", ctrMenu + 1);
            scanf("%d", &pickedData);
            getchar();
        } while (pickedData < 1 || pickedData > ctrMenu + 1);
        printf("Successfully added to order list!\n\n");
        printf("Press Enter to continue");
        getchar();
        return ListOrderMenu[pickedData - 1];
    }
}