// fibonacci
#include <stdio.h>

int fib(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return fib(n-1) + fib(n-2);
}

int main() {
    printf("%d ", fib(10));
    return 0;
}

// TAD (tipo abstrato de dados)
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;