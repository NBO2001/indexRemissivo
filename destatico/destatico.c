#include "stdio.h"
#include "stdlib.h"
#include "destatico.h"


struct TDestatico{
    int tamanho;
    int ocupacao;
    TEntrada* entradas;
};

TEntrada criar_entrada(int chave, void* info){
    TEntrada entrada;
    entrada.chave = chave;
    entrada.info= info;
    return entrada;

}
TDestatico* criar_destatico(int tamanho){
    TDestatico* de = malloc(sizeof(TDestatico));
    de->tamanho = tamanho;
    de->ocupacao = 0;
    de->entradas = malloc(sizeof(TEntrada)*de->tamanho);
    return de;
}

void inserir_destatico(TDestatico* de, TEntrada entrada){
    de->entradas[de->ocupacao]=entrada;
    de->ocupacao++;
}

void* buscar_destatico(TDestatico* de, int chave){
    //busca binaria
    void* entrada = NULL;
    int meio, encontrou = 0;
    int inicio = 0, fim= de->ocupacao-1;
    while((!encontrou)&&(inicio<=fim)){
        meio=(inicio+fim)/2;
        if(de->entradas[meio].chave>chave){
            inicio = meio + 1;
        }
        else if(de->entradas[meio].chave<chave){
            fim= meio - 1;
        }
        else{
            encontrou = 1;
            entrada = de->entradas[meio].info;
        }
    }
    return entrada;
    
}

