#include "stdio.h"
#include "stdlib.h"
#include "tipoPalavra.h"
#include <assert.h>
#include <string.h>
#include "../../libs/quick_sort_generico/quick_sort.h"

struct typePage{
    void * document;
    double pontuation;
    unsigned long int recorrences;
    unsigned int * totDocs;
};

struct tipoPalavra{
    char* palavra;  
    typePage* pages;
    int lenght;
    int ocupation;
};

tipoPalavra* criarPalavra(){
    tipoPalavra* p = malloc(sizeof(tipoPalavra));
    p->lenght = 2;
    p->pages = calloc(sizeof(typePage), p->lenght);
    p->ocupation = 0;
    return p;
}

typePage _createPage(void* documentPage, unsigned int * totDocs){

    typePage page;
    page.document = documentPage;
    page.recorrences = 1;
    page.totDocs = totDocs;

    return page;

}

void setPage(tipoPalavra*p, void* documentPage,  unsigned int * totDocs){

    if((p->ocupation != 0 ) && (memcmp(p->pages[p->ocupation - 1].document,documentPage, sizeof(int)) == 0) ){
        p->pages[p->ocupation - 1].recorrences++;
    }else{
        
        if(p->ocupation >= p->lenght){
            p->lenght = p->lenght * 2;
            p->pages = realloc(p->pages,sizeof(typePage)*p->lenght);
            
            assert(p->pages != NULL);
        }

        p->pages[p->ocupation] = _createPage(documentPage, totDocs);
        p->ocupation++;
        
    }
    
}

void* getDocument(tipoPalavra* p, int index){ return p->pages[index].document; }

unsigned long int getRecorreces(tipoPalavra* p, int index){
    return p->pages[index].recorrences;
}

double getPontuation(tipoPalavra* p, int index){
    return p->pages[index].pontuation;
}

void setPontuation(tipoPalavra* p, int index, double pontuation){
   p->pages[index].pontuation = pontuation;
}

void setPalavra(tipoPalavra*p, char* palavra){

    p->palavra = malloc(sizeof(char)*150);

    strcpy(p->palavra,palavra);
    
    
}

char* getPalavra(tipoPalavra* p){
    
    return p->palavra;
}

int getLenPages(tipoPalavra* p){
    return p->ocupation;
}

unsigned int * getDocTot(tipoPalavra* p, int index){
    return p->pages[index].totDocs;
}

int _comparatorPages(void * pageA,void * pageB){

    typePage* pageAA = pageA;
    typePage* pageBB = pageB;
    if(pageAA->pontuation < pageBB->pontuation){
        return -1;
    }else if(pageAA->pontuation > pageBB->pontuation){
        return 1;
    }else{
        return 0;
    }
    
}


void sortingPages(tipoPalavra* p){

    sort(p->pages,p->ocupation,sizeof(typePage),&_comparatorPages);
    
}

