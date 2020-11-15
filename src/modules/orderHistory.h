#ifndef MOD_ORDERHISTORY_H
#define MOD_ORDERHISTORY_H

//int ctrHistory;
int i;

time_t rawtime;
struct tm *timeinfo;

typedef struct timeNow{
	int year;
	int mon;
	int day;
	int hour;
	int minute;
	int second;
	char amPm[5];
} timeNow;

typedef struct inputHistory{
	char name[5000];
   int price;
   char topping[25];
   float callories;
   char flavor[25];
   char size[5];
   timeNow now;
} history;

void waktu();
void putHistoryBeverages(Beverages minumanBaru);
void putHistoryDesserts(Desserts dessertBaru);
void VieworderHistory();

#endif /* MOD_ORDERHISTORY_H */
