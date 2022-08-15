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

typedef struct {
    Bebida *first;
    Bebida *last;
} ListaBebidas;

struct _cliente {
    int codigo;
    char nome[50];
    int cpf;
    int idade;
    int fiado;
    struct _cliente *prev;
    struct _cliente *next;
};
typedef struct _cliente Cliente;

typedef struct {
    Cliente *first;
    Cliente *last;
} ListaClientes;