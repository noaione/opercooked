#ifndef MOD_BEVERAGES_H
#define MOD_BEVERAGES_H

typedef struct Beverages {
    char name[5000];
    int price;
    char flavor[25];
    char size;
    int modifier;
    int cooktime;
} Beverages;

Beverages *createBeverages(void);

#endif /* MOD_BEVERAGES_H */