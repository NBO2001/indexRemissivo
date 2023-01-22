#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/tipoPalavra/tipoPalavra.h"
#include "../../libs/utils/utils.h"
#include "../../libs/typeDocument/typeDocument.h"

void showPagesInOrder(tipoPalavra * palavra, int tam){

    int i = 0;
    typeDocument * doc;

    while (i < tam){
        doc = getDocument(palavra,i);
        printf("page %d: { pontuation: %lf},\n", 
        getNumPage(doc),
        getPontuation(palavra,i));
        i++;

    }

}


int main(int argc, char * argv[]){

    tipoPalavra** palavras = calloc(sizeof(tipoPalavra*),14000);
    
    unsigned int totDocs = 0;

    assert(palavras != NULL);

    char tmpWord[150];

    int i = 0;

    FILE * fp = fopen(argv[1],"r");

    while (fscanf(fp,"%s", tmpWord)==1){
        
        palavras[i] = criarPalavra();

        setPalavra(palavras[i], tmpWord);
        
        i++;
    }

    fclose(fp);


    for(int j=0; j < 5; j++){
        typeDocument * doc = tpDocument();
        setNumPage(doc,totDocs);
        setPage(palavras[0],doc, &totDocs);
        setPontuation(palavras[0],j,(0.25 + j));
        totDocs++;

    }
    
    showPagesInOrder(palavras[0],5);

    sortingPages(palavras[0]);
    
    printf(" *-*- \n");

    showPagesInOrder(palavras[0],5);
    
   


}
