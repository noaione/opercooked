#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cookingProcess.h"
#include "beverages.h"
#include "desserts.h"

struct CookingNode {
    cookingData *menu;
    CookingNode *next;
} *cookHead, *cookTail, *cookCurr;

CookingNode *createCookingNode(cookingData *menu) {
    CookingNode *temp = (CookingNode *)malloc(sizeof(CookingNode));
    temp->menu = menu;
    temp->next = NULL;
    return temp;
};

CookedNode *createCookedNode(cookingData *menu) {
    CookedNode *temp = (CookedNode *)malloc(sizeof(CookingNode));
    temp->cooked = menu;
    temp->next = NULL;
    return temp;
}

cookingData processing[1000];
int ctr = 0;

void cookBeverage(Beverages *newDrink) {
    cookingData *menu_temp = (cookingData *)malloc(sizeof(cookingData));
    menu_temp->drinks = newDrink;
    menu_temp->price = newDrink->price;
    menu_temp->timer = newDrink->cooktime;
    menu_temp->type = 1;
    
    CookingNode *temp = createCookingNode(menu_temp);
    if (!cookHead) {
        cookHead = cookTail = temp;
    } else {
        cookTail->next = temp;
        cookTail = temp;
    }
}

void cookDessert(Dessert *newDessert) {
    cookingData *menu_temp = (cookingData *)malloc(sizeof(cookingData));
    menu_temp->desserts = newDessert;
    menu_temp->price = newDessert->Price;
    menu_temp->timer = newDessert->Totaltime;
    menu_temp->type = 0;

    CookingNode *temp = createCookingNode(menu_temp);
    if (!cookHead) {
        cookHead = cookTail = temp;
    } else {
        cookTail->next = temp;
        cookTail = temp;
    }
}

void cancelAndFreeOngoingCooking() {
	if (!cookHead) { // empty list
		return;
	} else {
		cookCurr = cookHead;
		free(cookCurr->menu);
        cookCurr = cookCurr->next;
        free(cookHead);
		while (cookHead) {
			free(cookCurr->menu);
            CookingNode *nextAddr = cookCurr->next;
            free(cookCurr);
			cookCurr = nextAddr;
		}
	}
}

void freeCookedDataList(CookedNode *headRef) {
    if (!headRef) {
        return;
    } else {
        CookedNode *curr = headRef;
        free(curr->cooked);
        curr = curr->next;
        free(headRef);
        while (curr) {
            free(curr->cooked);
            CookedNode *nextAddr = curr->next;
            free(curr);
            curr = nextAddr;
        }
    }
}

// Reimplementation of https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
// I don't know if it's works or not :^), this is so scuffed
// god help me :DDDDDDDDDDDDDDDDDDD
cookingData *popCookingNode(int position) {
    cookingData *bogus_data = (cookingData *)malloc(sizeof(cookingData));
    bogus_data->type = -1;
    bogus_data->price = 0;
    printf("Yoinking position: %d\n", position);
    if (!cookHead) {
        return bogus_data;
    }
    CookingNode *temp = cookHead;
    if (position == 0) {
        puts("Found on position zero, returning immediatly.");
        cookHead = temp->next;
        cookingData *temp_data = cookHead->menu;
        free(temp);
        // remove placeholder
        free(bogus_data);
        printf("Data type found: %d\n", temp_data->type);
        return temp_data;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        puts("Found bogus data TwT");
        return bogus_data;
    }

    puts("YEAH FOUND IT POG");
    CookingNode *next = temp->next->next;
    cookingData *return_data = temp->next->menu;
    free(temp->next);
    // remove placeholder
    free(bogus_data);
    temp->next = next;

    // reset tail
    if (next == NULL) {
        puts("NEXT ONE IS NULL, setting to last temp.");
        cookTail = temp;
    } else {
        CookingNode *lastValid = temp;
        while (next) {
            lastValid = temp;
            temp = temp->next;
        }
        cookTail = lastValid;
    }
    puts("RETURNING DATA POG");
    return return_data;
}

void printCookingProcess(cookingData *menu, int pos) {
    if (menu->type == 1) {
        printf("| %d\t| Drink\t\t| %s\t\t\t| $%d\t| %ds\t\t|\n", pos + 1, menu->drinks->name, menu->price, menu->timer);
    } else if (menu->type == 0) {
        printf("| %d\t| Dessert\t\t| %s\t\t\t| $%d\t| %ds\t\t|\n", pos + 1, menu->desserts->Dessert_Name, menu->price, menu->timer);
    }
}

CookedNode *viewCookProcess() {
    if (!cookHead) { //klo kosong
        puts("There is no cooking process recently!");
        puts("");
        puts("Press Enter to continue");
        getchar();
        struct CookedNode *tempCooked = NULL;
        return tempCooked;
    } else {
        cookCurr = cookHead;
        int ongoing_curr = 0;
        int curr_pos = 0;
        struct CookedNode *headRefCooked = NULL;
        struct CookedNode *currRefCooked = headRefCooked;
        //print header tabel
        printf("| No\t| Type\t\t| Name\t\t\t\t| Price\t| Time Left\t|\n");
		printf("---------------------------------------------------------------------------------\n");
        // print or add the first data.
        if (cookCurr->menu->timer <= 0) {
            CookedNode *temp_addition = createCookedNode(popCookingNode(ongoing_curr));
            if (!headRefCooked) {
                headRefCooked = temp_addition;
            } else {
                currRefCooked->next = temp_addition;
                currRefCooked = temp_addition;
            }
        } else {
            printCookingProcess(cookCurr->menu, ongoing_curr);
            cookCurr->menu->timer -= 10;
            ongoing_curr++;
        }

        cookCurr = cookCurr->next;
        curr_pos++;
        // print or add rest of the data.
        while (cookCurr) {
            if (cookCurr->menu->timer <= 0) {
                CookedNode *temp_add = createCookedNode(popCookingNode(ongoing_curr));
                if (!headRefCooked) {
                    headRefCooked = temp_add;
                } else {
                    currRefCooked->next = temp_add;
                    currRefCooked = temp_add;
                }
            } else {
                printCookingProcess(cookCurr->menu, ongoing_curr);
                cookCurr->menu->timer -= 10;
                ongoing_curr++;
            }
            cookCurr = cookCurr->next;
            curr_pos++;
        }

        puts("");
        puts("Press Enter to return to main menu");
        getchar();
        return headRefCooked;
    }
}