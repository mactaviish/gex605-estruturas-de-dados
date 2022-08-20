#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void printMenu() {
    system("clear");
    setbuf(stdin, NULL);
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

void voltarMenu() {
    setbuf(stdin, NULL);
    printf("\nPressione qualquer tecla para voltar...");
    getchar();
}

void printTitle(char title[50]) {
    system("clear");
    printf("%s\n\n", title);
}

Bebida *buscaBebida(ListaBebidas *list, int cod) {
    Bebida *aux = list->first;
    while (aux != NULL) {
        if (aux->codigo == cod) {
            return aux;
        }
        aux = aux->next;
    }

    return NULL;
}

Cliente *buscaCliente(ListaClientes *list, int cod) {
    Cliente *aux = list->first;
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
        printTitle("Cadastro de Bebidas");
        printf("Código: ");
        scanf("%d", &new->codigo);
        if (buscaBebida(list, new->codigo) != NULL) {
            printf("Código %d já cadastrado!\n", new->codigo);
            voltarMenu();
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

void mostraBebida(ListaBebidas *list) {
    Bebida *aux = list->first;

    printTitle("Bebidas");
    if (aux == NULL) {
        printf("Nenhuma bebida cadastrada!\n");
    } else {
        while (aux != NULL) {
            printf("Código: %d\n", aux->codigo);
            printf("Nome: %s\n", aux->nome);
            printf("Conteúdo: %d\n", aux->conteudo);
            printf("Preço: R$%.2lf\n", aux->preco);
            printf("Quantidade: %d\n\n", aux->estoque);
            aux = aux->next;
        }
    }
    voltarMenu();
}

void compraBebida(ListaBebidas *list) {
    int codigo = 0, qtd = 0;
    Bebida *bebida = NULL;

    while (1) {
        printTitle("Compra de Bebidas");
        printf("Código: ");
        scanf("%d", &codigo);
        bebida = buscaBebida(list, codigo);
        if (bebida == NULL) {
            printf("Código %d não existe!\n", codigo);
            voltarMenu();
            continue;
        } else {
            break;
        }
    }

    printf("Quantidade: ");
    scanf("%d", &qtd);
    bebida->estoque += qtd;
}

void vendeBebida(ListaBebidas *bebList, ListaClientes *cliList) {
    int cod;
    Cliente *cli = NULL;
    printf("Cliente (CPF): ");
    scanf("%d", &cod);
    cli = buscaCliente(cliList, cod);

    while (1) {
        
    }
}

void invalidOption() {
    system("clear");
    printf("Opção inválida!\n");
    voltarMenu();
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
            case 2:
                mostraBebida(bebList);
                break;
            case 3:
                compraBebida(bebList);
                break;
            case 4:
                vendeBebida(bebList, cliList);
                break;
            default:
                invalidOption();
                break;
        }
    }

    return 0;
}