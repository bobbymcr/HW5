#include <cstdlib>

#include "utils.h"

// this function generates a random number r
// r = 0 if a = b
// a <= r < b, if a < b
// b <= r < a, if b < a

int randomNumber (int a, int b) {
    if (b == a) 
        return b;

    if (b > a)
        return a + (rand() % (b - a));

    return b + (rand() % (a - b));
}
