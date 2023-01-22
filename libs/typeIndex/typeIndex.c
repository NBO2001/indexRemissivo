#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "stdlib.h"
#include "typeIndex.h"
#include "../typeDynamicDictionary/typeDynamicDictionary.h"
#include "../utils/utils.h"
#include "../typeDocument/typeDocument.h"
#include "../typeStopWords/typeStopWords.h"
#include "../tipoPalavra/tipoPalavra.h"

struct typeIndex{
    typeDynamicDictionary *words;
};



typeIndex * newTypeIndex(char * documentName, void * stopWordsData){

    typeStopWord * stopWords = stopWordsData;
    typeIndex * index = malloc(sizeof(typeIndex));
    int tamDocuments = 40;
    int indexDoc = 0;
    long int contWords = 0;

    typeDocument* *documents = malloc(sizeof(typeDocument *)*tamDocuments);

    FILE * fp = fopen(documentName,"r");
    
    char tmp[150];

    index->words = newDynamicDictionary(14000);

    while(fscanf(fp,"%s", tmp) == 1){

        if(strcmp(tmp,"PA") == 0){


            if(indexDoc >= (tamDocuments-2)){
                tamDocuments *= 2;
                documents = realloc(documents, sizeof(typeDocument *)*tamDocuments);
                assert(documents != NULL);
            }
            
            documents[indexDoc] = tpDocument();
            setNumPage(documents[indexDoc],indexDoc);
            setLenWords(documents[indexDoc],0);
            indexDoc++;

        }else{

            cleaningWord(tmp);
            
            if((!isStopWord(stopWords,tmp)) && (lenStr(tmp) > 0)){

                setLenWords(documents[indexDoc-1],getLenWords(documents[indexDoc-1])+1);

                tipoPalavra* word = searchDynamicDictionary(index->words,tmp,150);
                
                if(!word){
                    
                    word = criarPalavra();
                    setPalavra(word,tmp);
                    
                    insertDynamicDictionary(index->words,tmp,150,word,sizeWord());
                    
                }else{
                    
                    setPage(word,documents[indexDoc-1],&indexDoc);
                }
                
            }
        }

    }

    fclose(fp);
    
    return index;

}