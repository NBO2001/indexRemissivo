#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/tipoPalavra/tipoPalavra.h"
#include "../../libs/typeDocument/typeDocument.h"
#include "../../libs/utils/utils.h"


void showPagesInOrder(tipoPalavra * palavra, int tam){

    int i = 0;
    typeDocument * doc;

    while (i < tam){
        doc = getDocument(palavra,i);
        unsigned long int recorrencias = getRecorreces(palavra,i);
        int totWords = getLenWords(doc);
        unsigned int * totDoc = getDocTot(palavra,i);
        printf("\t page %d: { pontuation: %lf},\n", getNumPage(doc), getPontuation(palavra,i));
        i++;

    }

}

void calculatorPontuations(tipoPalavra * palavra, int tam){

    int i = 0;
    typeDocument * doc;
    
    while (i < tam){
        doc = getDocument(palavra,i);
        int recorrencias = getRecorreces(palavra,i);
        int totWords = getLenWords(doc);
        unsigned int * totDoc = getDocTot(palavra,i);

        double pontuation = tfidf(recorrencias,totWords,tam,(*totDoc));
        
        setPontuation(palavra,i,pontuation);

        assert(pontuation == getPontuation(palavra,i));
        i++;

    }
    //sortingPages(palavra);
    

}


void wdMostre(tipoPalavra * palavra){
    
    calculatorPontuations(palavra,getLenPages(palavra));
    printf("{ palavra: %s, pages: \n",getPalavra(palavra));
    showPagesInOrder(palavra,getLenPages(palavra));
    printf("}\n");

}

void showVector(tipoPalavra * * palavras){

    int i = 0;
    printf("[ ");
    while (palavras[i] != NULL){
        printf("%s, ",getPalavra(palavras[i]));
      
        i++;
    }
    printf(" ]\n");

}
int main(int argc, char * argv[]){

    int tam = 14000;
    char tmpWord[150];
    int tolPages = 0;
    int indexPage = 0;
    int i = 0;
    tipoPalavra * * palavras = calloc(sizeof(tipoPalavra*),tam);
    
    typeDocument * doc;
    
    FILE * fp = fopen(argv[1],"r");

    while (fscanf(fp,"%s", tmpWord)==1){
        if(strcmp(tmpWord,"PA") == 0){
            doc = malloc(sizeof(typeDocument*));
            doc = tpDocument();
            setNumPage(doc,tolPages);
            setLenWords(doc,0);
            tolPages++;
        }else{
            setLenWords(doc,getLenWords(doc)+1);
            int findend = -1;
            
            i = 0;
            
            while (palavras[i] != NULL){
                
                if(strcmp(getPalavra(palavras[i]),tmpWord) == 0){
                    findend = i;
                }
                i++;
            }
          
            if(findend >= 0){
                setPage(palavras[findend],doc, &tolPages);
            }else{

                
                palavras[indexPage] = criarPalavra();
                setPalavra(palavras[indexPage],tmpWord);
                
                assert(strcmp(getPalavra(palavras[indexPage]), tmpWord) == 0);

                setPage(palavras[indexPage],doc, &tolPages);

                indexPage++;
            }
            
        }
    }
    
    
    fclose(fp);

    // i=0;
    // while (palavras[i] != NULL){
    //     printf("*-*-* I: %d **-*-*-*-*\n", i);
    //     wdMostre(palavras[i]);
    //     i++;
    // }
    
    wdMostre(palavras[1]);

}