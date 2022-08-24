#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define TRUE 1
#define FALSE 0

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
    system("clear");
}

ListaBebidas *initBebidas() {
    ListaBebidas *result = malloc(sizeof(ListaBebidas));
    result->first = NULL;
    result->last = NULL;
    return result;
}

ListaClientes *initClientes() {
    ListaClientes *result = malloc(sizeof(ListaClientes));
    result->first = NULL;
    result->last = NULL;
    return result;
}

int existeBebida(ListaBebidas *list) {
    if (list->first == NULL) {
        printf("Não há bebidas cadastradas.\n");
        voltarMenu();
        return FALSE;
    }
    return TRUE;
}

int existeCliente(ListaClientes *list) {
    if (list->first == NULL) {
        printf("Não há clientes cadastrados.\n");
        voltarMenu();
        return FALSE;
    }
    return TRUE;
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
    printf("Cliente %d não existe!\n\n", cod);
    return NULL;
}

void cadastraBebida(ListaBebidas *list) {
    Bebida *new = malloc(sizeof(Bebida));

    printf("Código: ");
    scanf("%d", &new->codigo);

    if (buscaBebida(list, new->codigo) != NULL) {
        printf("Código %d já cadastrado!\n", new->codigo);
        cadastraBebida(list);
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

    if (existeBebida(list) == TRUE) {
        while (aux != NULL) {
            printf("Código: %d\n", aux->codigo);
            printf("Nome: %s\n", aux->nome);
            printf("Conteúdo: %d\n", aux->conteudo);
            printf("Preço: R$%.2lf\n", aux->preco);
            printf("Quantidade: %d\n\n", aux->estoque);
            aux = aux->next;
        }
        voltarMenu();
    }
}

void compraBebida(ListaBebidas *list) {
    int codigo = 0, qtd = 0;
    Bebida *bebida = NULL;
    
    if (existeBebida(list) == TRUE) {
        printf("Código: ");
        scanf("%d", &codigo);
        bebida = buscaBebida(list, codigo);

        if (bebida == NULL) {
            printf("Código %d não existe!\n\n", codigo);
            compraBebida(list);
        }

        printf("Quantidade: ");
        scanf("%d", &qtd);
        bebida->estoque += qtd;
    }
}

void vendeBebida(ListaBebidas *bebList, ListaClientes *cliList) {
    int cod;
    Cliente *cli;
    Bebida *beb;
    if ((existeBebida(bebList) == TRUE) && (existeCliente(cliList) == TRUE)) {
        printf("Cliente: ");
        scanf("%d", &cod);
        cli = buscaCliente(cliList, cod);
        if (cli == NULL) {
            printf("Cliente %d não existe!\n\n", cod);
            return;
        }
        printf("Bebida: ");
        scanf("%d", &cod);
        beb = buscaBebida(bebList, cod);
        if (beb == NULL) {
            printf("Bebida %d não existe!\n\n", cod);
            return;
        }
        printf("Quantidade: ");
        scanf("%d", &cod);
        if (beb->estoque >= cod) {
            printf("Temos apenas %d em estoque!\n\n", beb->estoque);
            return;
        }

        
        voltarMenu();
    }
}

void invalidOption() {
    system("clear");
    printf("Opção inválida!\n");
    voltarMenu();
}

int main() {
    int opcao = 666;
    ListaBebidas *bebList = initBebidas();
    ListaClientes *cliList = initClientes();

    while (opcao != 0) {
        printMenu();

        scanf("%d", &opcao);
        printf("\n");
        system("clear");
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