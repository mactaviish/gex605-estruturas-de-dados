#include <stdio.h>

struct _pilha {
    char link[100];
    struct _pilha *ant;
    struct _pilha *prox;
};
typedef struct _pilha Pilha;

void printLast(Pilha *pilha) {
    if (pilha != NULL) {
        printf("%s\n", pilha->link);

        pilha = pilha->ant;
        free(pilha->prox);
        pilha->prox = NULL;
    }
}

void addPilha(Pilha *pilha, char link[100]) {
    Pilha *novo = malloc(sizeof(Pilha));
    strcpy(novo->link, link);
    novo->ant = pilha;
    novo->prox = NULL;
    if (pilha != NULL) {
        pilha->prox = novo;
    }
    pilha = novo;
}

int main() {
    char opcao[100] = '';
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->ant = NULL;
    pilha->prox = NULL;

    while (opcao != 'E') {
        scanf("%s", &opcao);

        switch (opcao) {
            case 'E':
                break;
            case 'B':
                printLast(pilha);
                break;
            default:
                addPilha(pilha, opcao);
                break;
        }
    }

    return 0;
}