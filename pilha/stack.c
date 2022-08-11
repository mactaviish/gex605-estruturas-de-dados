#include <stdio.h>
#include <stdlib.h>

struct _element {
    char value;
    struct _element *next;
};
typedef struct _element Element;

typedef struct {
    Element *top;
} Stack;

char pop(Stack *stack) {
    Element *aux = stack->top;
    char result = aux->value;

    if (stack->top == NULL) {
        return -1;
    }

    // stack->top = !stack->top ? NULL : stack->top->next;
    stack->top = stack->top->next;
    free(aux);
    return result;
}

void push(Stack *stack, char value) {
    Element *new = malloc(sizeof(Element));
    new->value = value;
    new->next = NULL;
    if (stack->top == NULL) {
        stack->top = new;
        return;
    }
    
    new->next = stack->top;
    stack->top = new;
}

void printStack(Stack *stack) {
    Element *aux = stack->top;
    while (aux != NULL) {
        printf("%c\n", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

int main() {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;

    push(stack, 'A');
    push(stack, 'B');
    push(stack, 'C');
    push(stack, 'D');

    pop(stack, 'D');

    printStack(stack);

    return 0;
}


int main() {
    char string[50];
    scanf("%s", string);

    while(string[i] != '\0') {
        if ((string[i] == '(') || (string[i] == '[') || (string[i] == '{')) {
            
        }
    }

}