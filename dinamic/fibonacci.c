#include "fibonacci.h"

int fibonacci(unsigned int n){
    if (n == 0)
    {
        return n;
    }
    unsigned int total = 1;
    while(n >= 1)
    {
        total *= n;
        n--;
    }
}

 