#ifndef MOD_ORDERHISTORY_H
#define MOD_ORDERHISTORY_H

#include <time.h>
#include "desserts.h"
#include "beverages.h"

//int ctrHistory;

typedef struct timeNow {
	int year;
	int mon;
	int day;
	int hour;
	int minute;
	int second;
	char amPm[5];
} timeNow;

typedef struct inputHistory {
	char name[5000];
	int price;
	char topping[25];
	float callories;
	char flavor[25];
	char size;
	timeNow now;
} inputHistory;

void waktu();
void putHistoryBeverages(Beverages *minumanBaru);
void putHistoryDesserts(Dessert *dessertBaru);
void viewOrderHistory();

#endif /* MOD_ORDERHISTORY_H */
