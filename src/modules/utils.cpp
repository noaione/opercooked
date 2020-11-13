#include <time.h>
#include <stdlib.h>
#include "utils.h"

// Generate Random Number with min max range
int randrange(int min, int max) {
    // Seed it.
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}