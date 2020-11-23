#ifndef MOD_COOKINGPROCESS_H
#define MOD_COOKINGPROCESS_H

#include "beverages.h"
#include "desserts.h"

typedef struct cookingData {
    Beverages *drinks;
    Dessert *desserts;
    int timer;
    int price;
    int type;
} cookingData;

struct CookedNode {
    cookingData *cooked;
    CookedNode *next;
};

void cookBeverage(Beverages *newDrink);
void cookDessert(Dessert *newDessert);
void cancelAndFreeOngoingCooking();
void freeCookedDataList(CookedNode *headRef);
CookedNode *viewCookProcess();

#endif