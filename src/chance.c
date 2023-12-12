#include <time.h>
#include <stdlib.h>

int randomChance(int min, int max) {
    return (rand() % (max - min + 1)) + min; 
}
