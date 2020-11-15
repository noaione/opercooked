#include <stdio.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "beverages.h"
#include "desserts.h"
#include "orderHistory.h"

// import module ini di file main.cpp
// ->	#include "modules/orderHistory.h"

history histo[100];
int ctrHistory = 0;

void waktu()
{
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	histo[ctrHistory].now.year = timeinfo->tm_year;
	histo[ctrHistory].now.mon = timeinfo->tm_mon;
	histo[ctrHistory].now.day = timeinfo->tm_mday;
	histo[ctrHistory].now.hour = (timeinfo->tm_hour > 12) ? timeinfo->tm_hour - 12 : timeinfo->tm_hour;
	histo[ctrHistory].now.minute = timeinfo->tm_min;
	histo[ctrHistory].now.second = timeinfo->tm_sec;
	(timeinfo->tm_hour > 12) ? strcpy(histo[ctrHistory].now.amPm, "PM") : strcpy(histo[ctrHistory].now.amPm, "AM");
}

// panggil fungsi ini tepat setelah beverage selesai dibuat untuk menambahkan history
void putHistoryBeverages(Beverages minumanBaru)
{
	strcpy(histo[ctrHistory].name, minumanBaru.name);
	histo[ctrHistory].price = minumanBaru.price;
	strcpy(histo[ctrHistory].flavor, minumanBaru.flavor);
	strcpy(histo[ctrHistory].size, minumanBaru.size);
	strcpy(histo[ctrHistory].topping, "-");
	histo[ctrHistory].callories = -1; // not defined
	waktu();

	ctrHistory++;
}

// panggil fungsi ini tepat setelah dessert selesai dibuat untuk menambahkan history
void putHistoryDesserts(Desserts dessertBaru)
{
	strcpy(histo[ctrHistory].name, dessertBaru.name);
	histo[ctrHistory].price = dessertBaru.price;
	strcpy(histo[ctrHistory].topping, dessertBaru.topping);
	histo[ctrHistory].callories = dessertBaru.callories;
	strcpy(histo[ctrHistory].flavor, "-");
	strcpy(histo[ctrHistory].size, "-");
	waktu();

	ctrHistory++;
}

// viewHistory
void orderHistory()
{
	if (ctrHistory != 0)
	{
		// Print Header
		i = 0;
		printf("| No\t| Name\t\t\t| Price\t| Topping\t\t| Callories\t| Flavor\t\t| Size\t| Order Time\t\t\t|\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
		// Print Table
		while (i < ctrHistory)
		{
			//Beverage
			if (histo[i].callories == -1)
			{
				printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| -\t| %s\t\t| %s\t| %04d/%02d/%02d %02d:%02d:%02d %s\t\t|\n", i + 1, histo[i].name, histo[i].price, histo[i].topping, histo[i].flavor, histo[i].size,
					   histo[i].now.year + 1900, histo[i].now.mon, histo[i].now.day, histo[i].now.hour, histo[i].now.minute, histo[i].now.second, histo[i].now.amPm);
			}
			else
			{
				//Desserts
				printf("| %d\t| %s\t\t\t| %d\t| %s\t\t| %f\t| %s\t\t| %s\t| %04d/%02d/%02d %02d:%02d:%02d %s\t\t|\n", i + 1, histo[i].name, histo[i].price, histo[i].topping, histo[i].callories, histo[i].flavor, histo[i].size,
					   histo[i].now.year + 1900, histo[i].now.mon, histo[i].now.day, histo[i].now.hour, histo[i].now.minute, histo[i].now.second, histo[i].now.amPm);
			}
		}
	}
	else
	{
		// pass to main menu
		printf("Press Enter to Continue");
		getchar();
		// buat label di main menu dengan cara "mainMenu:" (tanpa tanda petik)
		goto mainMenu;
	}
}
