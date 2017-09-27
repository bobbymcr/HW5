// Some (just one) utility functions needed at various places in the program

#ifndef UTILS_H
#define UTILS_H

// this function generates a random INTEGER r.
// the value of r depends on the two parameters of this function as follows
// r = 0 if a = b
// a <= r < b, if a < b
// b <= r < a, if b < a
int randomNumber (int a, int b);

#endif