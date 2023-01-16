#include "stdio.h"
#include "stdlib.h"
#include "tipoPalavra.h"


struct tipoPalavra{
    int recurrence;
    void* *tupla;
    char* palavra;  
};

tipoPalavra* criarPalavra(){
    tipoPalavra* palavra;
    palavra = (tipoPalavra*)malloc(sizeof(tipoPalavra));

    return palavra;
}

void setRecurrence(tipoPalavra* p, int recurrence){
    p->recurrence = recurrence;
}

int getRecurrence(tipoPalavra*p){
    return p->recurrence;
}

void setTupla(tipoPalavra*p, void* *tupla){
    p->tupla = tupla;
}
void* getTupla(tipoPalavra* p){
    return p->tupla;

}

void setPalavra(tipoPalavra*p, char* palavra){
    p->palavra = palavra;
}
char* getPalavra(tipoPalavra* p){
    return p->palavra;
}
