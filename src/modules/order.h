#ifndef MOD_ORDER_H
#define MOD_ORDER_H

#include "beverages.h"
#include "desserts.h"

typedef struct MenuOpercooked {
    Beverages beverageData;
    Dessert dessertData;
    char type;
} MenuOpercooked;

MenuOpercooked newOrder();

#endif