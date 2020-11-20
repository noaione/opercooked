#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "beverages.h"

// Import modul ini di file `main.cpp` di folder `src` kayak gini:
// #include "modules/beverages.h"
//
// Lalu panggil fungsinya di file `main.cpp` kayak gini:
// Beverages minumanBaru = createBeverages();

// Generate a cook time from modifier
int createBeveragesCookTime(int flavor_mod) {
    return randrange(10, 50) + (flavor_mod * 10);
}

// Fungsi utama
Beverages *createBeverages(void) {
    Beverages *newDrinks = (Beverages *)malloc(sizeof(Beverages));
    while (strlen(newDrinks->name) < 5) {
        printf("Input the name [at least 5 characters]: ");
        scanf("%[^\n]", newDrinks->name);
        getchar();
    }
    while (newDrinks->price < 10 || newDrinks->price > 500) {
        printf("Input the price [10 - 500]: $ ");
        scanf("%d", &newDrinks->price);
        getchar();
    }
    newDrinks->modifier = -1;
    while (newDrinks->modifier < 0) {
        printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        scanf("%[^\n]", newDrinks->flavor);
        getchar();
        if (strcmp(newDrinks->flavor, "Mint") == 0) {
            newDrinks->modifier = 1;
        } else if (strcmp(newDrinks->flavor, "Mix Berry") == 0)
        {
            newDrinks->modifier = 2;
        } else if (strcmp(newDrinks->flavor, "Cheese") == 0)
        {
            newDrinks->modifier = 3;
        }
    }
    bool shouldBreak = false;
    while (!shouldBreak) {
        printf("Input the size ['S' | 'M' | 'L'](Case Sensitive): ");
        scanf("%c", &newDrinks->size);
        getchar();
        // S, M, L
        if (newDrinks->size == 83 || newDrinks->size == 77 || newDrinks->size == 76) {
            shouldBreak = true;
        }
    }
    newDrinks->cooktime = createBeveragesCookTime(newDrinks->modifier);
    return newDrinks;
}
