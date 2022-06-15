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

// Exercício 1
#include <stdio.h>

int potencia(int base, int expoente) {
	if (expoente == 0)
		expoente = 1;
	else
	if (expoente == 1)
		expoente = base
	else 
		base = base * potencia(base, expoente - 1);
	
    printf("%d", valor);
	return base;
}

int main() {
	int valor = potencia(4, 4);

	return 0;
}

// Exercício 3
#include <stdio.h>

int mdc(int m, int n) {
	if (n == 0)
		m;
	else
		m = mdc(n, m%n);
	return m;
}

int main() {
	int valor = mdc(12, 18);

    printf("\n%d", valor);
	return 0;
}