typedef struct noValor {
    int valor;
    struct noValor *prox;
} NoValor;

typedef struct noLinha {
    noValor *valores;
    struct noLinha *prox;    
} NoLinha;
