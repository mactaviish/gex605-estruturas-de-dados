#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void printMenu() {
    system("clear");
    printf("Escolha uma das opções abaixo:\n\n");
    printf("[ 1 ] Cadastrar bebida\n");
    printf("[ 2 ] Mostrar bebidas\n");
    printf("[ 3 ] Comprar bebida\n");
    printf("[ 4 ] Vender bebida\n");
    printf("[ 5 ] Cadastrar cliente\n");
    printf("[ 6 ] Mostrar clientes\n");
    printf("[ 0 ] Sair do sistema\n");
    printf("> ");
}

Bebida *magic(ListaBebidas *list, int cod) {
    Bebida *aux = list->first;
    while (aux != NULL) {
        if (aux->codigo == cod) {
            return aux;
        }
        aux = aux->next;
    }

    return NULL;
}

void cadastraBebida(ListaBebidas *list) {
    Bebida *new = malloc(sizeof(Bebida));

    while (1) {
        system("clear");
        printf("Cadastro de Bebidas\n\n");
        printf("Código: ");
        scanf("%d", &new->codigo);
        if (magic(list, new->codigo) != NULL) {
            printf("Código %d já cadastrado!\n", new->codigo);
            system("sleep 3");
            continue;
        } else {
            break;
        }
    }

    printf("Nome: ");
    scanf("%s", new->nome);
    printf("Conteúdo: ");
    scanf("%d", &new->conteudo);
    printf("Preço: ");
    scanf("%lf", &new->preco);
    printf("Quantidade: ");
    scanf("%d", &new->estoque);
    new->next = NULL;

    if (list->first == NULL) {
        list->first = new;
    } else {
        list->last->next = new;
        new->prev = list->last;
    }
    list->last = new;
}

void invalidOption() {
    system("clear");
    printf("Opção inválida!\n");
    system("sleep 3");
}

int main() {
    int opcao;
    ListaBebidas *bebList = malloc(sizeof(ListaBebidas));
    bebList->first = NULL;
    bebList->last = NULL;

    while (opcao != 0) {
        printMenu();

        scanf("%d", &opcao);
        printf("\n");
        switch (opcao) {
            case 1:
                cadastraBebida(bebList);
                break;
            default:
                invalidOption();
                break;
        }
    }

    return 0;
}