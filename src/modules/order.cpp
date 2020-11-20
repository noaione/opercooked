#include <stdio.h>
#include <stdlib.h>

#include "order.h"
#include "beverages.h"
#include "desserts.h"

// Maximum 100

struct MenuNode {
    MenuOpercooked *menu;
    MenuNode *next;
} *menuHead, *menuCurr, *menuTail;

MenuNode *createMenuNode(MenuOpercooked *menu) {
    MenuNode *temp = (MenuNode *)malloc(sizeof(MenuNode));
    temp->menu = menu;
    temp->next = NULL;
    return temp;
}

void addBeveragesToList(Beverages *menuBaru)
{
    MenuOpercooked *data = (MenuOpercooked *)malloc(sizeof(MenuOpercooked));
    data->beverageData = menuBaru;
    data->type = 'b'; // b for beverages

    MenuNode *temp = createMenuNode(data);
    if (!menuHead) {
        menuHead = menuTail = temp;
    } else {
        menuTail->next = temp;
        menuTail = temp;
    }
}

void addDessertToList(Dessert *menuBaru)
{
    MenuOpercooked *data = (MenuOpercooked *)malloc(sizeof(MenuOpercooked));
    data->dessertData = menuBaru;
    data->type = 'd'; // d for dessert

    MenuNode *temp = createMenuNode(data);
    if (!menuHead) {
        menuHead = menuTail = temp;
    } else {
        menuTail->next = temp;
        menuTail = temp;
    }
}

void removeAndFreeAllMenu() {
	if (!menuHead) { // empty list
		return;
	} else {
		menuCurr = menuHead;
		free(menuCurr->menu);
        menuCurr = menuCurr->next;
        free(menuHead);
        int ctrMenu = 1;
		while (menuCurr) {
			free(menuCurr->menu);
            MenuNode *nextAddr = menuCurr->next;
            free(menuCurr);
			menuCurr = nextAddr;
            ctrMenu++;
		}
	}
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

MenuOpercooked *getMenuFromInteger(int needed_pos) {
    // reset cursor to head
    menuCurr = menuHead;
    if (!menuHead) {
        MenuOpercooked *emptyPlaceholder = (MenuOpercooked *)malloc(sizeof(MenuOpercooked));
        emptyPlaceholder->type = 'e'; // set as garbage data, don't forget to free it.
        return emptyPlaceholder;
    }
    if (needed_pos == 0) {
        return menuHead->menu;
    }
    int curr_pos = 0;
    for (int i = 0; i < needed_pos; i++) {
        if (i == needed_pos) {
            if (!menuCurr) {
                // number match, but data is missing :(
                MenuOpercooked *emptyPlaceholder = (MenuOpercooked *)malloc(sizeof(MenuOpercooked));
                emptyPlaceholder->type = 'e'; // set as garbage data, don't forget to free it.
                return emptyPlaceholder;
            }
            // data found
            return menuCurr->menu;
        }
        menuCurr = menuCurr->next;
    }
    // not found.
    MenuOpercooked *emptyPlaceholder = (MenuOpercooked *)malloc(sizeof(MenuOpercooked));
    emptyPlaceholder->type = 'e'; // set as garbage data, don't forget to free it.
    return emptyPlaceholder;
}

void printMenuData(MenuOpercooked *menu, int pos) {
    //Beverages
    if (menu->type == 'b') 
    {
        printf("| %d\t| %s\t\t\t| %d\t| -\t\t| -\t| %s\t\t| %c\t|\n", pos, menu->beverageData->name, menu->beverageData->price, menu->beverageData->flavor, menu->beverageData->size);
    }
    //Desserts
    else 
    {
        printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| %.2f\t| -\t\t| -\t|\n", pos, menu->dessertData->Dessert_Name, menu->dessertData->Price, menu->dessertData->Topping, menu->dessertData->callories);
    }
}

MenuOpercooked *newOrder()
{
    if (!menuHead)
    {
        printf("There is no Dessert or Drink on the List!\n\n");
        printf("Press Enter to continue");
        getchar();
        MenuOpercooked *emptyPlaceholder = (MenuOpercooked *)malloc(sizeof(MenuOpercooked));
        emptyPlaceholder->type = 'e'; // set as garbage data, don't forget to free it.
        return emptyPlaceholder;
    }
    else 
    {
        // generate table
        // reset head
        menuCurr = menuHead;
        int curr_pos = 0;
        int ctrMenu = 1;
        // print header
        printf("| No\t| Name\t\t\t| Price\t| Topping\t\t| Callories\t| Flavor\t\t| Size\t|\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
        // print first data
        printMenuData(menuCurr->menu, curr_pos + 1);
        menuCurr = menuCurr->next;
        curr_pos++;
        while (menuCurr) 
        {
            printMenuData(menuCurr->menu, curr_pos + 1);
            menuCurr = menuCurr->next;
            curr_pos++;
            ctrMenu++;
        }
        int pickedData = 0;
        do 
        {
            printf("Choose a menu to order [1 - %d]: ", ctrMenu);
            scanf("%d", &pickedData);
            getchar();
        } while (pickedData < 1 || pickedData > ctrMenu);
        printf("Successfully added to order list!\n\n");
        printf("Press Enter to continue");
        getchar();
        return getMenuFromInteger(pickedData - 1);
    }
}