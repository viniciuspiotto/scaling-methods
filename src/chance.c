#include <time.h>

int random_chance(int min, int max) {
    return (rand() % (max - min + 1)) + min; 
}
