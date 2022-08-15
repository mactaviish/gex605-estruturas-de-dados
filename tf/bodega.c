#include <stdio.h>
#include "utils.h"

void printMenu() {
    system(“clear”);
    printf("Escolha uma das opções abaixo:\n");
    printf("[ 1 ] Cadastrar bebida\n");
    printf("[ 2 ] Mostrar bebidas\n");
    printf("[ 3 ] Comprar bebida\n");
    printf("[ 4 ] Vender bebida\n");
    printf("[ 5 ] Cadastrar cliente\n");
    printf("[ 6 ] Mostrar clientes\n");
    printf("[ 0 ] Sair do sistema\n");
}

int main() {
    printMenu();

    return 0;
}