#include <stdio.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "beverages.h"
#include "desserts.h"
#include "orderHistory.h"

// import module ini di file main.cpp
// ->	#include "modules/orderHistory.h"

inputHistory histo[100];
int ctrHistory = 0;

void waktu()
{
	time_t rawtime;
	time(&rawtime);
	struct tm *timeinfo;
	timeinfo = localtime(&rawtime);
	histo[ctrHistory].now.year = timeinfo->tm_year;
	histo[ctrHistory].now.mon = timeinfo->tm_mon;
	histo[ctrHistory].now.day = timeinfo->tm_mday;
	histo[ctrHistory].now.hour = (timeinfo->tm_hour > 12) ? timeinfo->tm_hour - 12 : timeinfo->tm_hour;
	histo[ctrHistory].now.minute = timeinfo->tm_min;
	histo[ctrHistory].now.second = timeinfo->tm_sec;
	(timeinfo->tm_hour > 12) ? strcpy(histo[ctrHistory].now.amPm, "PM") : strcpy(histo[ctrHistory].now.amPm, "AM");
}

// panggil fungsi ini tepat setelah memanggil fungsi createBeverages() untuk menambahkan history
void putHistoryBeverages(Beverages minumanBaru)
{
	strcpy(histo[ctrHistory].name, minumanBaru.name);
	histo[ctrHistory].price = minumanBaru.price;
	strcpy(histo[ctrHistory].flavor, minumanBaru.flavor);
	histo[ctrHistory].size = minumanBaru.size;
	strcpy(histo[ctrHistory].topping, "-");
	histo[ctrHistory].callories = -1; // not defined
	waktu();

	ctrHistory++;
}

// panggil fungsi ini tepat setelah memanggil fungsi createDessert() untuk menambahkan history
void putHistoryDesserts(Dessert dessertBaru)
{
	strcpy(histo[ctrHistory].name, dessertBaru.Dessert_Name);
	histo[ctrHistory].price = dessertBaru.Price;
	strcpy(histo[ctrHistory].topping, dessertBaru.Topping);
	histo[ctrHistory].callories = dessertBaru.callories;
	strcpy(histo[ctrHistory].flavor, "-");
	histo[ctrHistory].size = '-';
	waktu();

	ctrHistory++;
}

// viewHistory
void viewOrderHistory()
{
	if (ctrHistory != 0)
	{
		// Print Header
		int i = 0;
		printf("| No\t| Name\t\t\t\t| Price\t| Topping\t| Callories\t| Flavor\t| Size\t| Order Time\t\t\t\t|\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
		// Print Table
		while (i < ctrHistory)
		{
			// Beverage
			if (histo[i].callories == -1)
			{
				printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| -\t\t| %s\t| %c\t| %04d/%02d/%02d %02d:%02d:%02d %s\t\t|\n", i + 1, histo[i].name, histo[i].price, histo[i].topping, histo[i].flavor, histo[i].size,
					   histo[i].now.year + 1900, histo[i].now.mon, histo[i].now.day, histo[i].now.hour, histo[i].now.minute, histo[i].now.second, histo[i].now.amPm);
			}
			else
			{
				// Desserts
				printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| %.2f\t\t| %s\t\t| %c\t| %04d/%02d/%02d %02d:%02d:%02d %s\t\t|\n", i + 1, histo[i].name, histo[i].price, histo[i].topping, histo[i].callories, histo[i].flavor, histo[i].size,
					   histo[i].now.year + 1900, histo[i].now.mon, histo[i].now.day, histo[i].now.hour, histo[i].now.minute, histo[i].now.second, histo[i].now.amPm);
			}
			i++;
		}
	}
	else
	{
		// pass to main menu
		printf("There is no order history!\n\n");
		printf("Press Enter to continue");
		getchar();
	}
}
