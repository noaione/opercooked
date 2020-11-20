#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "utils.h"
#include "beverages.h"
#include "desserts.h"
#include "orderHistory.h"

// import module ini di file main.cpp
// ->	#include "modules/orderHistory.h"

struct HistoryNode {
	inputHistory *histo;
	HistoryNode *next;
} *histHead, *histTail, *histCurr;

HistoryNode *createHistoryNode(inputHistory *value) {
	HistoryNode *temp = (HistoryNode *)malloc(sizeof(HistoryNode));
	temp->histo = value;
	temp->next = NULL;
	return temp;
}

timeNow waktu()
{
	time_t rawtime;
	time(&rawtime);
	struct tm *timeinfo;
	timeinfo = localtime(&rawtime);
	timeNow now;
	now.year = timeinfo->tm_year;
	now.mon = timeinfo->tm_mon;
	now.day = timeinfo->tm_mday;
	now.hour = (timeinfo->tm_hour > 12) ? timeinfo->tm_hour - 12 : timeinfo->tm_hour;
	now.minute = timeinfo->tm_min;
	now.second = timeinfo->tm_sec;
	(timeinfo->tm_hour > 12) ? strcpy(now.amPm, "PM") : strcpy(now.amPm, "AM");
	return now;
}

// panggil fungsi ini tepat setelah memanggil fungsi createBeverages() untuk menambahkan history
void putHistoryBeverages(Beverages *minumanBaru)
{
	inputHistory *data = (inputHistory *)malloc(sizeof(inputHistory));
	strcpy(data->name, minumanBaru->name);
	data->price = minumanBaru->price;
	strcpy(data->flavor, minumanBaru->flavor);
	data->size = minumanBaru->size;
	strcpy(data->topping, "-");
	data->callories = -1; // not defined
	data->now = waktu();

	HistoryNode *temp = createHistoryNode(data);
	if (!histHead) {
		histHead = histTail = temp;
	} else {
		histTail->next = temp;
		histTail = temp;
	}
}

// panggil fungsi ini tepat setelah memanggil fungsi createDessert() untuk menambahkan history
void putHistoryDesserts(Dessert *dessertBaru)
{
	inputHistory *data = (inputHistory *)malloc(sizeof(inputHistory));
	strcpy(data->name, dessertBaru->Dessert_Name);
	data->price = dessertBaru->Price;
	strcpy(data->topping, dessertBaru->Topping);
	data->callories = dessertBaru->callories;
	strcpy(data->flavor, "-");
	data->size = '-'; // not defined
	data->now = waktu();

	HistoryNode *temp = createHistoryNode(data);
	if (!histHead) {
		histHead = histTail = temp;
	} else {
		histTail->next = temp;
		histTail = temp;
	}
}

void nukeAndFreeHistoryList() {
	if (!histHead) { // empty list
		return;
	} else {
		histCurr = histHead;
		free(histCurr->histo);
		histCurr = histCurr->next;
		free(histHead);
		while (histCurr) {
			free(histCurr->histo);
			HistoryNode *nextAddr = histCurr->next;
			free(histCurr);
			histCurr = nextAddr;
		}
	}
}

void printOrderData(inputHistory *histo, int pos) {
	if (histo->callories == -1) {
		// Beverage
		printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| -\t\t| %s\t| %c\t| %04d/%02d/%02d %02d:%02d:%02d %s\t\t|\n", pos, histo->name, histo->price, histo->topping, histo->flavor, histo->size,
				histo->now.year + 1900, histo->now.mon, histo->now.day, histo->now.hour, histo->now.minute, histo->now.second, histo->now.amPm);
	} else {
		// Desserts
		printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| %.2f\t\t| %s\t\t| %c\t| %04d/%02d/%02d %02d:%02d:%02d %s\t\t|\n", pos, histo->name, histo->price, histo->topping, histo->callories, histo->flavor, histo->size,
				histo->now.year + 1900, histo->now.mon, histo->now.day, histo->now.hour, histo->now.minute, histo->now.second, histo->now.amPm);
	}
}

// viewHistory
void viewOrderHistory()
{
	if (!histHead) {
		// pass to main menu
		printf("There is no order history!\n\n");
		printf("Press Enter to continue");
		getchar();
	} else {
		// Print Header
		histCurr = histHead; // reset cursor to head
		printf("| No\t| Name\t\t\t\t| Price\t| Topping\t| Callories\t| Flavor\t| Size\t| Order Time\t\t\t\t|\n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
		// Print first data
		int curr_pos = 1;
		printOrderData(histCurr->histo, 1);
		// Print rest of the data.
		histCurr = histCurr->next;
		while (histCurr) {
			curr_pos += 1;
			printOrderData(histCurr->histo, curr_pos);
			histCurr = histCurr->next;
		}
		puts("");
        puts("Press Enter to return to main menu");
        getchar();
	}
}
