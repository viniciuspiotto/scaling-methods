#include <time.h>
#include <stdlib.h>

/**
 * Return an integer between min and max.
 * @param int min
 * @param int max
 * 
 * @return int
 */
int randomChance(int min, int max) {
    return (rand() % (max - min + 1)) + min; 
}
