typedef struct {
    char nome[50];
    int cnpj;
} Empresa;

struct _bebida {
    int codigo;
    char nome[50];
    int conteudo;
    double preco;
    int estoque;
    struct _bebida *prev;
    struct _bebida *next;
};
typedef struct _bebida Bebida;