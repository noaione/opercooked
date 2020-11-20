#ifndef MOD_DESSERTS_H
#define MOD_DESSERTS_H

typedef struct Dessert{
    int Extra_Time;
    char Dessert_Name[200];
    char Topping[25];
    int Totaltime;
    int Price; 
    int modifier;
    float callories;
} Dessert;

Dessert *addDessert(void);

#endif /* MOD_DESSERTS_H */