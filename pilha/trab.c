#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _pilha {
    char link[100];
    struct _pilha *ant;
    struct _pilha *prox;
};
typedef struct _pilha Pilha;

Pilha *printLast(Pilha *pilha) {
    if (pilha == NULL)
        printf("Vazio\n");
    else {
        printf("%s\n", pilha->link);

        if (pilha->ant == NULL) 
            pilha = NULL;
        else {
            pilha = pilha->ant;
            free(pilha->prox);
            pilha->prox = NULL;
        }
    }
    return pilha;
}

Pilha *addPilha(Pilha *pilha, char link[50]) {
    Pilha *novo = malloc(sizeof(Pilha));
    strcpy(novo->link, link);
    novo->ant = pilha;
    novo->prox = NULL;
    if (pilha != NULL) {
        pilha->prox = novo;
    }
    pilha = novo;
    return pilha;
}

void limparPilha(Pilha *pilha) {
    Pilha *aux = pilha;

    if (aux == NULL)
        printf("!\n");
    else {
        while (aux != NULL) {
            printf("@\n");
            if (aux->ant == NULL) {
                free(aux);
                aux = NULL;
            } else {
                aux = aux->ant;
                free(aux->prox);
            }
        }
    }
}

int main() {
    char opcao[50];
    Pilha *pilha = NULL;

    while (1) {
        scanf("%s", &opcao);

        if (strcmp(opcao, "E") == 0) {
            limparPilha(pilha);
            return 0;
        }
        else
        if (strcmp(opcao, "B") == 0)
            pilha = printLast(pilha);
        else
            pilha = addPilha(pilha, opcao);
    }

    return 0;
}