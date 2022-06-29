#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

struct _aluno {
    char matricula[10];
    char nome[40];
    Data data_nascimento;
    float nota;
    struct _aluno *next;
};

typedef struct _aluno Aluno;

Aluno *addAluno(Aluno *first, Aluno *new) {
    Aluno *aux;

    if (first == NULL)
        return new;

    aux = first;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    
    aux->next = new;
    return first;
}

Aluno *createAluno() {
    Aluno *aux = malloc(sizeof(Aluno));

    scanf("%s", &aux->matricula);
    scanf("%s", &aux->nome);
    scanf("%d/%d/%d", &aux->data_nascimento.dia, &aux->data_nascimento.mes, &aux->data_nascimento.ano);
    scanf("%f", &aux->nota);
    aux->next = NULL;

    return aux;
}

void deleteAluno(Aluno *first) {
    Aluno *aux;
    char matricula[10];

    scanf("%s", matricula);

    if (first == NULL)
        printf("Lista Vazia!\n");
        return;

    if (strcmp(first->matricula, matricula) == 0) {
        aux = first;
        first = first->next;
        free(aux);
        return;
    }

    aux = first;
    while (aux->next != NULL) {
        if (strcmp(aux->next->matricula, matricula) == 0) {
            Aluno *aux2 = aux->next;
            aux->next = aux->next->next;
            free(aux2);
            return;
        }
        aux = aux->next;
    }
}

void listAluno(Aluno *first) {
    Aluno *aux;

    if (first == NULL)
        printf("Lista Vazia!\n");
        return;

    aux = first;
    while (aux != NULL) {
        printf("%s, %s, %d/%d/%d %.2f\n", aux->matricula, aux->nome, aux->data_nascimento.dia, aux->data_nascimento.mes, aux->data_nascimento.ano, aux->nota);
        aux = aux->next;
    }
}

void inverseListAluno(Aluno *first) {
    Aluno *aux;

    if (first == NULL)
        printf("Lista Vazia!\n");
        return;

    aux = first;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    while (aux != NULL) {
        printf("%s, %s, %d/%d/%d %.2f\n", aux->matricula, aux->nome, aux->data_nascimento.dia, aux->data_nascimento.mes, aux->data_nascimento.ano, aux->nota);
        aux = aux->next;
    }
}

void countAluno(Aluno *first) {
    Aluno *aux;
    int count = 0;

    if (first == NULL)
        printf("Lista Vazia!\n");
        return;

    aux = first;
    while (aux != NULL) {
        count++;
        aux = aux->next;
    }

    printf("%d\n", count);
}

void cleanMemory(Aluno *first) {
    Aluno *aux;

    if (first == NULL)
        return;

    aux = first;
    while (aux != NULL) {
        first = first->next;
        free(aux);
        aux = first;
        printf("-");
    }
}

int main() {
    int opcao;
    Aluno *first = NULL;

    while (opcao != 0) {
        printf("Opção 1: Incluir elemento na lista\n");
        printf("Opção 2: Excluir elemento da lista\n");
        printf("Opção 3: Listar todos os elementos da lista na ordem de inclusão\n");
        printf("Opção 4: Listar todos os elementos da lista na ordem inversa a inclusão\n");
        printf("Opção 5: Apresentar quantos elementos existem na lista\n");
        printf("Opção 0: Sair do programa\n");

        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                first = addAluno(first, createAluno());
                break;
            case 2:
                deleteAluno(first);
                break;
            case 3:
                listAluno(first);
                break;
            case 4:
                inverseListAluno(first);
                break;
            case 5:
                countAluno(first);
                break;
        }
    }

    return 0;
}