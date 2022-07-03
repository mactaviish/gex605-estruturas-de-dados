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

Aluno *createAluno() {
    Aluno *aux = (Aluno *)malloc(sizeof(Aluno));

    scanf("%s", &aux->matricula);
    scanf("%s", &aux->nome);
    scanf("%d/%d/%d", &aux->data_nascimento.dia, &aux->data_nascimento.mes, &aux->data_nascimento.ano);
    scanf("%f", &aux->nota);
    aux->next = NULL;

    return aux;
}

Aluno *addAluno(Aluno *first) {
    Aluno *aux, *new;
    new = createAluno();

    if (first == NULL)
        return new;

    aux = first;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    
    aux->next = new;
    return first;
}

void deleteAluno(Aluno *first) {
    Aluno *aux, *previous;
    char matricula[10];

    if (first == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    scanf("%s", matricula);

    for (aux=first; aux != NULL; aux=aux->next) {
        if (strcmp(aux->matricula, matricula) == 0) {
            if (aux == first) {
                first = aux->next;
                break;
            }
            previous->next = aux->next;
            break;
        }
        previous = aux;
    }
    
    if (aux != NULL)
        free(aux);
    return;
}

void listAluno(Aluno *first) {
    Aluno *aux;

    if (first == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    aux = first;
    while (aux != NULL) {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->data_nascimento.dia, aux->data_nascimento.mes, aux->data_nascimento.ano, aux->nota);
        aux = aux->next;
    }
}

void inverseListAluno(Aluno *first) {
    Aluno *aux;

    if (first == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    aux = first;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    while (aux != NULL) {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->data_nascimento.dia, aux->data_nascimento.mes, aux->data_nascimento.ano, aux->nota);
        aux = aux->next;
    }
}

void countAluno(Aluno *first) {
    Aluno *aux;
    int count = 0;

    if (first == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

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
    Aluno *first=NULL;

    printf("Opção 1: Incluir elemento na lista\n");
    printf("Opção 2: Excluir elemento da lista\n");
    printf("Opção 3: Listar todos os elementos da lista na ordem de inclusão\n");
    printf("Opção 4: Listar todos os elementos da lista na ordem inversa a inclusão\n");
    printf("Opção 5: Apresentar quantos elementos existem na lista\n");
    printf("Opção 0: Sair do programa\n");

    while (opcao != 0) {
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                first = addAluno(first);
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
            case 0:
                cleanMemory(first);
                break;
        }
    }

    return 0;
}
