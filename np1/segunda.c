// questao 2

#include <stdio.h>

typedef struct {
	double a;
	double b;
} Complexo;

Complexo setComplex(double real, double imaginario) {
	Complexo result;
	
	result.a = real;
	result.b = imaginario;

	return result;
}

Complexo sumComplex(Complexo num1, Complexo num2) {
	Complexo result;
	
	result.a = num1.a + num2.a;
	result.b = num1.b + num2.b;
	
	return result;
}

void printComplex(Complexo num) {
	printf("%f + %f i", num.a, num.b);
}

int main() {
	Complexo num1, num2, soma;
	num1 = setComplex(11,3);
	num2 = setComplex(3,11);
	
	soma sumComplex(num1, num2);
	
	printComplex(soma);
}
