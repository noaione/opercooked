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

typedef struct cookedData {
    cookingData cookedItems[500];
    int totalCooked;
} cookedData;

void cookBeverage(Beverages *newDrink);
void cookDessert(Dessert *newDessert);
cookedData viewCookProcess();

#endif