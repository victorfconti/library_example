#include <stdio.h>
#include "fibonacci.h"

int main(int argc, char *argv[]){
    unsigned int total = fibonacci(12);
    printf("%i", total);
    return 0; // Quando não há erro se retorna 0, caso contário se retorna o código de erro
}