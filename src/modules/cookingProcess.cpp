#include <stdio.h>
#include <string.h>

#include "cookingProcess.h"
#include "beverages.h"
#include "desserts.h"

cookingData processing[1000];
int ctr = 0;

void cookBeverage(Beverages *newDrink) {
    processing[ctr].drinks = newDrink;
    processing[ctr].price = newDrink->price;
    processing[ctr].timer = newDrink->cooktime;
    processing[ctr].type = 1;
    ctr++;
}

void cookDessert(Dessert *newDessert) {
    processing[ctr].desserts = newDessert;
    processing[ctr].price = newDessert->Price;
    processing[ctr].timer = newDessert->Totaltime;
    processing[ctr].type = 0;
    ctr++;
}

cookedData viewCookProcess() {
    if(ctr != 0) {
        cookedData finished;
        finished.totalCooked = -1;
        //print header tabel
        printf("| No\t| Type\t\t| Name\t\t\t\t| Price\t| Time Left\t|\n");
		printf("---------------------------------------------------------------------------------\n");

        //print tabel
        for(int i = 0; i < ctr; i++) {
            if (processing[i].timer <= 0) {
                finished.totalCooked++;
                finished.cookedItems[finished.totalCooked] = processing[i];
            } else {
                if (processing[i].type == 1) {
                    printf("| %d\t| Drink\t\t| %s\t\t\t| $%d\t| %ds\t\t|\n", i + 1, processing[i].drinks->name, processing[i].price, processing[i].timer);
                } else {
                    printf("| %d\t| Dessert\t\t| %s\t\t\t| $%d\t| %ds\t\t|\n", i + 1, processing[i].desserts->Dessert_Name, processing[i].price, processing[i].timer);
                }
                processing[i].timer -= 10;
            }
        }
        if (finished.totalCooked > -1) {
            ctr -= (finished.totalCooked + 1);
        }
        puts("");
        puts("Press Enter to return to main menu");
        getchar();
        return finished;
    } else { //klo kosong
        puts("There is no cooking process recently!");
        puts("");
        puts("Press Enter to continue");
        getchar();

        cookedData temp;
        temp.totalCooked = -1;
        return temp;
    }
}