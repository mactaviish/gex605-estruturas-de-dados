#include <stdio.h>

#define COUNT 10;

struct _node {
    int value;
    struct _node *left, *right;
};
typedef struct _node Node;

Node *addNode(Node *root, int value) {
    if (root == NULL) {
        root = malloc(sizeof(Node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else if (value < root->value) {
        root->left = addNode(root->left, value);
    } else {
        root->right = addNode(root->right, value);
    }
    return root;
}

void printNode(Node *root, int space) {
    int i;
    if (root == NULL)
        return;
    space += COUNT;
    printNode(root->right, space);
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printNode(root->left, space);
}

int main() {
    Node *root = NULL;

    root = addNode(root, 30);
    root = addNode(root, 51);
    root = addNode(root, 14);
    root = addNode(root, 43);
    root = addNode(root, 82);
    root = addNode(root, 21);
    root = addNode(root, 9);
    root = addNode(root, 3);
    root = addNode(root, 27);
    root = addNode(root, 99);

    printNode(root, 0);
    return 0;
}