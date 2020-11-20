#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "desserts.h"
#include "utils.h"

// Import modul ini di file `main.cpp` di folder `src` kayak gini:
// #include "modules/beverages.h"
//
// Lalu panggil fungsinya di file `main.cpp` kayak gini:
// Dessert desserBaru = addDessert();

void Checking_Topping(char Topping[], Dessert *dessert);
int Total_Time(int Extra_time);

Dessert *addDessert(void)
{
    Dessert *NewDessert = (Dessert *)malloc(sizeof(Dessert));
    //input nama makanan
    while (strlen(NewDessert->Dessert_Name) < 5)
    {
        printf("Input the name [at least 5 character]: ");
        scanf("%[^\n]", NewDessert->Dessert_Name);
        getchar();
    }
    //input harga makanan
    while (NewDessert->Price < 10 || NewDessert->Price > 500)
    {
        printf("Input the Price [10 - 500]: $ ");
        scanf("%d", &NewDessert->Price);
        getchar();
    }

    NewDessert->modifier = -1;
    while (NewDessert->modifier < 0)
    {
        printf("Input the Topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
        scanf("%s", NewDessert->Topping);
        getchar();
        int topping_len = strlen(NewDessert->Topping);
        for (int i = 0; i < topping_len; i++)
        {
            if (NewDessert->Topping[i] >= 'A' && NewDessert->Topping[i] <= 'Z')
            {
                NewDessert->Topping[i] += 32;
            }
        }
        Checking_Topping(NewDessert->Topping, NewDessert);
    }

    NewDessert->Totaltime = Total_Time(NewDessert->Extra_Time);
    // Kapitalisasi kembali.
    NewDessert->Topping[0] -= 32;
    while (NewDessert->callories < 1.00 || NewDessert->callories > 99.00)
    {
        printf("Insert callories [1.00 - 99.00]: ");
        scanf("%f", &NewDessert->callories);
        getchar();
    }
    return NewDessert;
}

void Checking_Topping(char Topping[], Dessert *dessert) //pengecekan jenis topping yang dipakai
{
    if (strcmp(Topping, "caramel") == 0)
    {
        dessert->Extra_Time = 10; //waktutambahann
        dessert->modifier = 1;    //untuk bantu menghentikan loop
    }
    else if (strcmp(Topping, "honey") == 0)
    {
        dessert->Extra_Time = 15; //waktutambahann
        dessert->modifier = 2;    //untuk bantu menghentikan loop
    }
    else if (strcmp(Topping, "syrup") == 0)
    {
        dessert->Extra_Time = 20; //waktutambahann
        dessert->modifier = 3;    //untuk bantu menghentikan loop
    }
}

// total waktu buat dessert
int Total_Time(int Extra_time)
{
    return randrange(10, 50) + Extra_time;
}