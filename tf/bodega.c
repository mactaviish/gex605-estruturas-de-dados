#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define TRUE 1
#define FALSE 0
#define IDADE_MINIMA 18

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
    printf("[ 7 ] Mostrar caderninho\n");
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

Caderninho *initCaderninho() {
    Caderninho *result = malloc(sizeof(Caderninho));
    result->first = NULL;
    result->last = NULL;
    return result;
}

int existeBebida(ListaBebidas *list) {
    if (list->first == NULL) {
        printf("Não há bebidas cadastradas!\n");
        voltarMenu();
        return FALSE;
    }
    return TRUE;
}

int existeCliente(ListaClientes *list) {
    if (list->first == NULL) {
        printf("Não há clientes cadastrados!\n");
        voltarMenu();
        return FALSE;
    }
    return TRUE;
}

int existeCaderninho(Caderninho *list) {
    if (list->first == NULL) {
        printf("Não há vendas no caderninho!\n");
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
    return NULL;
}

void cadastraBebida(ListaBebidas *list) {
    Bebida *new = malloc(sizeof(Bebida));

    printf("Código: ");
    setbuf(stdin, NULL);
    scanf("%d", &new->codigo);

    if (buscaBebida(list, new->codigo) != NULL) {
        printf("Código %d já cadastrado!\n\n", new->codigo);
        cadastraBebida(list);
        return;
    }

    printf("Nome: ");
    scanf("%s", new->nome);
    printf("Conteúdo: ");
    scanf("%d", &new->conteudo);
    printf("Preço: ");
    scanf("%lf", &new->preco);
    printf("Quantidade: ");
    scanf("%d", &new->estoque);
    printf("Teor Alcóolico: ");
    scanf("%lf", &new->teor);
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
            printf("Conteúdo: %dml\n", aux->conteudo);
            printf("Preço: R$%.2lf\n", aux->preco);
            printf("Quantidade: %d\n", aux->estoque);
            printf("Teor Alcóolico: %.2lf%%\n\n", aux->teor);
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
            return;
        }

        printf("Quantidade: ");
        scanf("%d", &qtd);
        bebida->estoque += qtd;
    }
}

Devedor *buscaDevedor(Caderninho *cad, int cod) {
    Devedor *aux = cad->first;

    while (aux != NULL) {
        if (aux->cli->codigo == cod) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

void adicionaCaderninho(Caderninho *cad, Cliente *cli, double valor) {
    Devedor *aux = buscaDevedor(cad, cli->codigo);

    if (aux == NULL) {
        aux = malloc(sizeof(Devedor));
        aux->cli = cli;
        aux->valor = valor;
        aux->next = NULL;

        if (cad->first == NULL) {
            cad->first = aux;
        } else {
            cad->last->next = aux;
            aux->prev = cad->last;
        }

        cad->last = aux;
    } else {
        aux->valor += valor;
    }

    printf("Você já está devendo R$%.2lf, fica esperto!\n\n", aux->valor);
}

void mostraCaderninho(Caderninho *list) {
    Devedor *aux = list->first;

    if (existeCaderninho(list) == TRUE) {
        while (aux != NULL) {
            printf("Cliente: %d - %s\n", aux->cli->codigo, aux->cli->nome);
            printf("Valor: R$%.2lf\n\n", aux->valor);
            aux = aux->next;
        }
        voltarMenu();
    }
}

void vendeBebida(ListaBebidas *bebList, ListaClientes *cliList, Caderninho *cad) {
    int cod, qtd;
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
            voltarMenu();
            return;
        } else
        if ((beb->teor > 0) && (cli->idade < IDADE_MINIMA)) {
            printf("Cliente '%d - %s' não pode comprar bebida alcoólica!\n\n", cli->codigo, cli->nome);
            voltarMenu();
            return;
        }

        printf("Quantidade: ");
        scanf("%d", &qtd);
        if (beb->estoque < qtd) {
            printf("Temos apenas %d em estoque!\n\n", beb->estoque);
            voltarMenu();
            return;
        }
        beb->estoque -= qtd;

        if (cli->fiado == 1) {
            printf("Será no caderninho? (1 - Sim / 2 - Não): ");
            scanf("%d", &cod);
            if (cod == 1) {
                adicionaCaderninho(cad, cli, beb->preco * qtd);
            } else {
                printf("Ficou R$%.2lf, meu consagrado!\n\n", beb->preco * qtd);
            }
        } else {
            printf("Ficou R$%.2lf, meu consagrado!\n\n", beb->preco * qtd);
        }
        
        voltarMenu();
    }
}

void cadastraCliente(ListaClientes *list) {
    Cliente *new = malloc(sizeof(Cliente));

    printf("Código: ");
    setbuf(stdin, NULL);
    scanf("%d", &new->codigo);

    if (buscaCliente(list, new->codigo) != NULL) {
        printf("Código %d já cadastrado!\n\n", new->codigo);
        cadastraCliente(list);
        return;
    }

    printf("Nome: ");
    scanf("%s", new->nome);
    printf("Idade: ");
    scanf("%d", &new->idade);
    printf("Pode vender fiado? (1 - Sim / 2 - Não): ");
    scanf("%d", &new->fiado);
    new->next = NULL;

    if (list->first == NULL) {
        list->first = new;
    } else {
        list->last->next = new;
        new->prev = list->last;
    }
    list->last = new;
}

void mostraCliente(ListaClientes *list) {
    Cliente *aux = list->first;

    if (existeCliente(list) == TRUE) {
        while (aux != NULL) {
            printf("Código: %d\n", aux->codigo);
            printf("Nome: %s\n", aux->nome);
            printf("CPF: %d\n", aux->cpf);
            printf("Idade: %d\n", aux->idade);
            printf("Pode vender fiado? %s\n\n", aux->fiado == 1 ? "Sim" : "Não");
            aux = aux->next;
        }
        voltarMenu();
    }
}

int limparBebida(ListaBebidas *list) {
    int result = 0;
    Bebida *aux = list->first;

    while (aux != NULL) {
        if (aux->next == NULL) {
            free(aux);
            aux = NULL;
        }
        else {
            aux = aux->next;
            free(aux->prev);
        }
        result++;
    }
    return result;
}

int limparCliente(ListaClientes *list) {
    int result = 0;
    Cliente *aux = list->first;

    while (aux != NULL) {
        if (aux->next == NULL) {
            free(aux);
            aux = NULL;
        }
        else {
            aux = aux->next;
            free(aux->prev);
        }
        result++;
    }
    return result;
}

int limparCaderninho(Caderninho *list) {
    int result = 0;
    Devedor *aux = list->first;

    while (aux != NULL) {
        if (aux->next == NULL) {
            free(aux);
            aux = NULL;
        }
        else {
            aux = aux->next;
            free(aux->prev);
        }
        result++;
    }
    return result;
}

void sair(ListaBebidas *bebList, ListaClientes *cliList, Caderninho *cad) {
    int qtd = 0;

    qtd = limparBebida(bebList) + limparCliente(cliList) + limparCaderninho(cad);
    printf("%d elementos foram liberados da memória!\n\n", qtd);
    printf("Até mais!\n");
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
    Caderninho *cad = initCaderninho();

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
                vendeBebida(bebList, cliList, cad);
                break;
            case 5:
                cadastraCliente(cliList);
                break;
            case 6:
                mostraCliente(cliList);
                break;
            case 7:
                mostraCaderninho(cad);
                break;
            case 0:
                sair(bebList, cliList, cad);
                break;
            default:
                invalidOption();
                break;
        }
    }

    return 0;
}