#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "beverages.h"

int createBeveragesCookTime(int flavor_mod) {
    return randrange(10, 50) + (flavor_mod * 10);
}
