#include <stdio.h>
#include <stdlib.h>

#define N 40

struct _func {
    int cod;
    char nome[N];
    double salario;
    struct _func *prev;
    struct _func *next;
};

typedef struct _func Funcionario;

typedef struct {
    Funcionario *first;
    Funcionario *last;
} List;

int isEmptyList(List *l) {
    return l->first == NULL;
}

Funcionario *magic(List *list, int cod) {
    Funcionario *aux;

    for (aux = list->first; aux->next != NULL; aux = aux->next) {
        if (aux->cod == cod)
            return aux;
    }
}

void addHead(List *list, Funcionario *new) {
    if (isEmptyList(list)) {
        list->first = new;
        list->last = new;
    } else {
        new->next = list->first;
        list->first = new;
    }
}

void addTail(List *list, Funcionario *new) {
    if (isEmptyList(list)) {
        list->first = new;
        list->last = new;
    } else {
        list->last->next = new;
        list->last = new;
    }
}

void addMiddle(List *list, Funcionario *new, int cod) {
    if (isEmptyList(list)) {
        list->first = new;
        list->last = new;
    } else {
        Funcionario *aux1 = list->first, *aux2 = NULL;

        new->next = magic(list, cod);
        new->prev = new->next->prev;
        new->next->prev = new;
        new->prev->next = new;
    }
}

void deleteElement(List *list, int cod) {
    Funcionario *aux = magic(list, cod);

    if (aux == list->first) {
        list->first = list->first->next;
        list->first->prev = NULL;
    } else
    if (aux == list->last) {
        list->last = list->last->prev;
        list->last->next = NULL;
    } else {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }
}

Funcionario *createFunc(int cod, char nome[N], double salario) {
    Funcionario *new;
    new->cod = cod;
    strcpy(new->nome, nome);
    new->salario = salario;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

int main() {
    int i;
    Funcionario *aux;
    List *list = malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;

    for (i = 1; i <= 5; i++) {
        addHead(list, createFunc(i, "Joao", (i * 1000)));
    }

    for (aux = list->first; aux != NULL; aux = aux->next) {
        printf("id>%d | salario>%f", aux->cod, aux->salario);
    }

    return 0;
}