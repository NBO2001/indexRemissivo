#ifndef T_DESTATICO
#define T_DESTATICO

typedef struct TEntrada TEntrada;
typedef struct TDestatico TDestatico;
struct TEntrada{
    int chave;
    void* info;
};

TDestatico* criar_destatico(int tamanho);

TEntrada criar_entrada(int chave, void* info);

void inserir_destatico(TDestatico* destatico, TEntrada info);

void* buscar_destatico(TDestatico* destatico, int chave);


#endif