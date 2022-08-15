#include <stdio.h>
#include "utils.h"

void printMenu() {
    printf("Escolha uma das opções abaixo:\n");
    printf("[ 1 ] Cadastrar bebida\n");
    printf("[ 2 ] Mostrar bebidas\n");
    printf("[ 3 ] Comprar bebida\n");
    printf("[ 4 ] Vender bebida\n");
    printf("[ 5 ] Cadastrar cliente\n");
    printf("[ 6 ] Mostrar clientes\n");
    printf("[ 0 ] Sair do sistema\n");
}

void cadastraBebida(ListaBebidas *list) {
    Bebida new = malloc(sizeof(Bebida));
    printf("Código:\n");
    scanf("%d", &new->codigo);
    printf("Nome:\n");
    scanf("%s", new->nome);
    printf("Conteúdo:\n");
    scanf("%s", new->conteudo);
    printf("Preço:\n");
    scanf("%f", &new->preco);
    printf("Quantidade:\n");
    scanf("%d", &new->quantidade);
    new->next = NULL;

    if (list->first == NULL) {
        list->first = new;
    } else {
        list->last->next = new;
    }
    list->last = new;
}

int main() {
    ListaBebidas *bebList = malloc(sizeof(ListaBebidas));
    bebList->first = NULL;
    bebList->last = NULL;

    int opcao;
    while (true) {
        printMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastraBebida(bebList);
                break;
        }
    }

    return 0;
}