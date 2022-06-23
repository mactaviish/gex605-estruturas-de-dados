#include <stdio.h>

struct _funcionario {
    int id;
    char nome[20];
    double salario;
    struct _funcionario *next;
};

typedef struct _funcionario Funcionario;

Funcionario *createFunc(int id, char nome[20], double salario) {
    Funcionario *aux = malloc(sizeof(Funcionario));

    aux->id = id;
    strcpy(aux->nome, nome);
    aux->salario = salario;
    aux->next = NULL;

    return aux;
}

Funcionario *addFunc(Funcionario *first, Funcionario *new) {
    Funcionario *aux;

    if (first == NULL)
        return new;

    aux = first;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    
    aux->next = new;
    return first;
}

void *printFuncs(Funcionario *first) {
    Funcionario *aux;

    for (aux = first; aux != NULL; aux = aux->next) {
        printf("ID: %d\n", aux->id);
        printf("Nome: %c\n", aux->nome);
        printf("Salário: %lf\n", aux->salario);
    }
}

int main() {
    int i;
    Funcionario *first=NULL, *novo;

    for (int i = 2; i < 10; i++) {
        snprintf(nome, sizeof(nome), "teste %d", i);
        novo = createFunc(1, "Jagunço", 3000.00);
        first = addFunc(first, novo);
    }
    
    printFuncs(first);

    return 0;
}