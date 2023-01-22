#include <stdio.h>
#include "stdlib.h"
#include "typeIndex.h"
#include "../ddinamico/ddinamico.h"
#include "../utils/utils.h"
#include "../typeDocument/typeDocument.h"
#include "../typeStopWords/typeStopWords.h"
#include "../tipoPalavra/tipoPalavra.h"

struct typeIndex{
    TDDinamico *words; 
};

void insertElDocs(
    typeDocument* *docs, 
    int *tamDocuments, 
    int *indexDoc,
    long int *startPage,
    long int *previus,
    long int *contWords,
    FILE * fp){

    typeDocument * tm = tpDocument();

    assert(tm != NULL);
    
    docs[(*indexDoc)] = tm;
    setNumPage(docs[(*indexDoc)], (*indexDoc));
    setStartP(docs[(*indexDoc)], (*startPage));
    setEndP(docs[(*indexDoc)], (*previus));
    setLenWords(docs[(*indexDoc)], (*contWords));

    (*indexDoc)++;

    (*startPage) = ftell(fp);
    (*contWords) = 0;

}



typeIndex * newTypeIndex(char * documentName, void * stopWordsData){

    typeStopWord * stopWords = stopWordsData;
    typeIndex * index = malloc(sizeof(typeIndex));
    int tamDocuments = 2;
    int indexDoc = 0;
    long int startPage = 0;
    long int previus = 0;
    long int contWords = 0;
    typeDocument* *documents = malloc(sizeof(typeDocument *)*tamDocuments);

    FILE * fp = fopen(documentName,"r");
    
    char tmp[150];

    index->words = criar_DD(12000,12000,sizeof(char)*150);


    char tmp[150];

    while(fscanf(fp,"%s", tmp) == 1){
        
        previus = ftell(fp) - strlen(tmp);

        if(strcmp(tmp,"PA") == 0){


            if(indexDoc >= (tamDocuments-2)){
                tamDocuments *= 2;
                documents = realloc(documents, sizeof(typeDocument *)*tamDocuments);
                assert(documents != NULL);
            }
            documents[indexDoc] = malloc(sizeof(typeDocument*));
            documents[indexDoc] = tpDocument();
            setNumPage(documents[indexDoc],indexDoc);
            setLenWords(documents[indexDoc],0);
            indexDoc++;

        }else{

            cleaningWord(tmp);
            
            if((!isStopWord(stopWords,tmp)) && (lenStr(tmp) > 0)){

                setLenWords(documents[indexDoc-1],getLenWords(documents[indexDoc-1])+1);

                tipoPalavra* word = buscar_DD(index->words,tmp);
                if(!word){
                    word = criarPalavra();
                    setPalavra(word,tmp);
                    inserir_DD(index->words,tmp,word);
                }else{
                    setPage(word,documents[indexDoc]);
                }
                
            }
        }

    }

    fclose(fp);
    
    return index;

}